#include <tr1/unordered_map>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cassert>

#include <gmpxx.h>

#include "MathMatrix.h"
#include "MathVector.h"
#include "ExactLogisticRegression.h"

//#define DEBUG (true)
#define DEBUG (false)

struct SufficientStatTypeHash{
  // use Python's hash of tuple
  //       value = 0x345678
  // for item in self:
  //     value = c_mul(1000003, value) ^ hash(item)
  // value = value ^ len(self)
  // if value == -1:
  //     value = -2
  // return value
  size_t operator()(const SufficientStatType& s) const{
    size_t value = 0x345678;
    size_t size = s.size();
    for (unsigned int i = 0; i < size; i++){
      value = (1000003 * value ) ^ s[i];
    }
    value ^= size;
    return value;
  }
};

// Hashmap:
// key: string
// value: index position (>=0), -1 means unfound
class HashMap {
 public:
  int find(const SufficientStatType& s) {
    if (statToPosMap.find(s) != statToPosMap.end()) {
      return statToPosMap[s];
    } else {
      return -1;
    }
  };
 public:
  int& operator[] (const SufficientStatType&s) {
    return statToPosMap[s];
  };
 public:
  void clear() {statToPosMap.clear();};
 private:
  std::tr1::unordered_map<SufficientStatType, int, SufficientStatTypeHash> statToPosMap;
};


ExactLogisticRegression::ExactLogisticRegression(){};
void ExactLogisticRegression::init(int p, int q){
  this->p = p ;
  this->q = q ;
  assert( q == 1);
  currentStage.clear();
  DistributionType v(1+p+q, 0);
  v.freq = 1;
  currentStage.push_back(v);
  assert(p + q == predictor.size());
  if (q != 1) {
    std::cerr << "Only 1 parameter of interested supported for now " <<std::endl;
    assert(false);
  }
  // check dimension of X and Y
  int nSample = response.size();
  assert(nSample > 0);
  for (int i = 0; i < (p+q); i++)
    assert(nSample == predictor[i].size());
};

//TODO:
// seprate MSA algorithm and fitting
int ExactLogisticRegression::iterate(int maxRound) {
  // calculate realization
  int nSample = response.size();
  SufficientStatType t(p+q,0);
  for (int stage = 0; stage < nSample; stage++) {
    for (int i = 0; i < p+q ; i++) {
      t[i] += response[stage] * predictor[i][stage];
    }
  }
  // calculate u, v which is the maximum and minimum boundary
  // definition: see (3.2), (3.3)
  // our implementation: see (3.7), (3.8)
  SufficientStatType u(p+q,0);
  SufficientStatType v(p+q,0);
  for (int stage = nSample - 1; stage >=0 ; stage--) {
    for (int i = 0; i < p + q; i ++ ) {
      u[i] += max(predictor[i][stage], 0);
      v[i] += min(predictor[i][stage], 0);
    }
  }

  // Multivariate-shift algorithm
  // Detail:
  //   base on currentStage, we put results to nextStage (refer to the SAS paper we calculate layer by layer)
  //   then we assign current stage from nextStage
  //   after all stages are process, the results are stored in the currentStage
  HashMap posHash;
  StageType nextStage;

  for (int stage = 1; stage <= nSample; stage++) {
    if DEBUG std::cout << "Stage "<< stage<< std::endl;
    std::cout << "Stage "<< stage<< std::endl;
    posHash.clear();
    nextStage.clear();
    
    // update if it is feasible boundary
    for (int i = 0; i < p + q; i++) {
      u[i] -= max(predictor[i][stage-1], 0);
      v[i] -= min(predictor[i][stage-1], 0);
    }

    for (StageTypeIter it = currentStage.begin(); it < currentStage.end(); it++) {
      // algorithm
      // calculate new statistics for y_{i+1}
      // check pos
      // push it to the nextStage
      //
      //   when y_{i+1} = 0
      if (this->isFeasible((*it).stat, u, v, t)) {
        SufficientStatType& key = (*it).stat;
        int pos = posHash.find(key);
        if (pos >= 0) {
          nextStage[pos].freq += (*it).freq;
        } else {
          posHash[key] = nextStage.size();
          nextStage.push_back(*it);
        }
      }
      // when y_{i+1} = 1            key = toString(*it, 1);
      DistributionType d  = (*it);
      for (int i = 0; i < (p+q); i++ ) {
        d.stat[i] += predictor[i][stage-1];
      }
      if (this->isFeasible(d.stat, u, v, t)) {
        SufficientStatType& key = d.stat;
        int pos = posHash.find(d.stat);
        if (pos >= 0) {
          nextStage[pos].freq += d.freq;
        } else {
          posHash[key] = nextStage.size();
          nextStage.push_back(d);
        }
      }
    }

    // sum up nextStage freqs
    if (DEBUG){
      mpz_class sum = 0;
      for (StageTypeIter iter = nextStage.begin(); iter< nextStage.end(); iter++) {
        sum += (*iter).freq;
      }
      std::cout << sum << std::endl;
    }

    std::swap(currentStage, nextStage);

    // output current stage
    if DEBUG printStage(currentStage);

  } // for stage

  // // find the realization position
  this->realizationPos = posHash.find(t);
  if (this->realizationPos < 0) {
    fprintf(stderr, "Hash collision happens!!\n");
    exit(1);
  }
  // filter useless contrains and obtain conditional dist.
  mpz_class c_t1_t0 = currentStage[realizationPos].freq; //C(t1, t0) ; frequncy of counts that generates realization
  mpz_class c_smaller =  0;  // C(t); # of more extreme case (in which u >= t_i )
  mpz_class c_bigger =  0;  // C(t); # of more extreme case than c_t1_t0
  mpz_class c_u_t = 0; // C(u, t) # of all cases
  nextStage.clear();
  int tmp_realization_index = 0;
  int tmp_min_index = -1;
  int tmp_max_index = -1;
  mpz_class tmp_min_freq = -1;
  mpz_class tmp_max_freq = -1;
  for (StageTypeIter iter = currentStage.begin(); iter < currentStage.end(); iter++) {
    // update realizationPos since we will filter some elements
    if (tmp_realization_index == this->realizationPos) {
      this->realizationPos = nextStage.size();
    }
    bool passed = true;
    for (int i = 0 ; i<p ; i++) {
      if ( (*iter).stat[i] != t[i]) {
        passed = false;
        break;
      }
    }
    // T0 = t0 cases
    if (passed) {
      if ( (*iter).stat[p] <= t[p] )
        c_smaller += (*iter).freq;
      if ( (*iter).stat[p] >= t[p] )
        c_bigger += (*iter).freq;
      c_u_t += (*iter).freq;
      // record max, min pos
      if (tmp_min_freq <= (*iter).freq || tmp_min_freq < 0) {
        tmp_min_freq = (*iter).freq;
        tmp_min_index = nextStage.size();
      }
      if (tmp_max_freq >= (*iter).freq || tmp_max_freq < 0) {
        tmp_max_freq = (*iter).freq;
        tmp_max_index = nextStage.size();
      }
      nextStage.push_back(*iter);
    }
    tmp_realization_index ++ ;
  }
  // fast way to: currentStage = nextStage;
  std::swap(currentStage, nextStage);
  assert(this->realizationPos < currentStage.size());
  // output current stage
  // printStage(currentStage);

  mpf_class tmp_pvalue_L = 1.0;
  tmp_pvalue_L *=  c_smaller;
  tmp_pvalue_L /= c_u_t; // 1e10: to avoid convert mpz_class to mpf_class (integer to float)
  mpf_class tmp_pvalue_G = 1.0;
  tmp_pvalue_G *= c_bigger;
  tmp_pvalue_G /= c_u_t; // 1e10: to avoid convert mpz_class to mpf_class (integer to float)
  if ( tmp_pvalue_L > tmp_pvalue_G) {
    this->pvalue = 2.0 * tmp_pvalue_G.get_d() ;
  } else {
    this->pvalue = 2.0 * tmp_pvalue_L.get_d() ;
  }

  if (this->pvalue > 1.0) {
    std::cout << "Trancate p-value to be less than 1.0\n";
    this->pvalue = 1.0;
  }
  std::cout << "exact p-value: c_smaller,c_bigger = " << c_smaller <<"," << c_bigger
            << " t_p = " << t[p]
            <<" c_u_t = "<< c_u_t<< "\n";
  printf("two side pvalue = %g\n", this->pvalue);
  printf("(less) pvalue = %g\n", tmp_pvalue_L.get_d());
  printf("(larger) pvalue = %g\n", tmp_pvalue_G.get_d());

  // output exact estimate of beta
  // when realization is the min/max freq, Newton-Ralphson won't converge (refer: SAS paper)
  // we will solve f(betai) = 1/2
  if (currentStage[this->realizationPos].freq == tmp_min_freq) {
    std::cerr << "Warning: beta_estimation is adjusted" << std::endl;
    this->beta = NewtonRalphson(maxRound, true, 0.5);
    this->upperCI = NAN;
    this->lowerCI = NewtonRalphson(maxRound, true, 0.025);
  }  else if (currentStage[this->realizationPos].freq == tmp_max_freq) {
    std::cerr << "Warning: beta_estimation is adjusted" << std::endl;
    this->beta = NewtonRalphson(maxRound, true, 0.5);
    this->upperCI = NewtonRalphson(maxRound, true, 0.975);
    this->lowerCI = NAN;
  } else {
    // we use Newton-Ralphson to maximize f(betai)
    this->beta = NewtonRalphson(maxRound, false, 0);
    this->upperCI = NewtonRalphson(maxRound, true, 0.975);
    this->lowerCI = NewtonRalphson(maxRound, true, 0.025);
  }
  if DEBUG std::cout << "beta = " << beta << std::endl;

  return 0;
};

void print(mpf_class& a) {
  std::cout << a << "\n";
}

/**
 * calculate  fbeta, fbetap, fbetapp at @param given beta
 * where: fbeta is f_beta(t_i |t_0) = C(t_i, t_0) exp(t_i beta_i) / ( \sum_u C(u, t_0) exp(u beta_i)
 * fbetap is the first derivative of fbeta
 * fbetapp is the first derivative of fbetap
 * NOTE: this condidtional distribution will be CHANGED after this step
 */
void ExactLogisticRegression::CalculateFBeta(double& fbeta, double& fbetap, double& fbetapp,  // p: derivative
                                             double beta) {
  const DistributionType& realization = currentStage[this->realizationPos];
  const unsigned int qIndex = realization.stat.size() - 1;
  const FreqType& C_t = realization.freq;
  const double ti = realization.stat[qIndex];

  // for (StageTypeIter iter = currentStage.begin(); iter < currentStage.end(); iter++ ) {
  //     (*iter).freq /= C_t;     // q(u) = C(t0,u) / C(t0, ti) = C(t0,u) / C(t)
  //     (*iter).stat[qIndex] -= ti; // u_minus_t = u' - t'
  // }


  mpf_class C0 = 0.0; // \sum_u q(u) * exp{ (u'-t') * beta }
  mpf_class C1 = 0.0; // \sum_u q(u) (u'-t') * exp{ (u'-t') * beta }
  mpf_class C2 = 0.0; // \sum_u q(u) (u'-t')^2 * exp{ (u'-t') * beta }

  mpf_class q_u = 0.0;
  double u_minus_t = 0.0;
  mpf_class Cu_exp_u_beta = 0.0;
  for (StageTypeIter iter = currentStage.begin(); iter < currentStage.end(); iter++ ) {
    q_u = 1.0 * (*iter).freq / C_t;         // q(u) = C(t0,u) / C(t0, ti) = C(t0,u) / C(t)
    u_minus_t = (*iter).stat[qIndex] - ti;  // u_minus_t = u' - t'
    // note beta maybe nan and thus crash the calculation
    Cu_exp_u_beta = q_u * exp(u_minus_t * beta);
    C0 += Cu_exp_u_beta;
    Cu_exp_u_beta *= u_minus_t * Cu_exp_u_beta;
    C1 += Cu_exp_u_beta;
    Cu_exp_u_beta *= u_minus_t * Cu_exp_u_beta;
    C2 += Cu_exp_u_beta;
  }
  mpf_class mpf_fbeta = 1.0 / C0;
  mpf_class mpf_fbeta2 = mpf_fbeta * mpf_fbeta;
  mpf_class mpf_fbeta3 = mpf_fbeta2 * mpf_fbeta;
  mpf_class mpf_fbeta_p = -C1 / mpf_fbeta2;
  mpf_class mpf_fbeta_pp = -C2 /mpf_fbeta2 + 2.0 * C1 * mpf_fbeta_p / mpf_fbeta3;
  fbeta = mpf_fbeta.get_d();
  fbetap = mpf_fbeta_p.get_d();
  fbetapp = mpf_fbeta_pp.get_d();

  // for (StageTypeIter iter = currentStage.begin(); iter < currentStage.end(); iter++ ) {
  //     u = (*iter).stat[qIndex];
  //     Cu = (*iter).freq;
  //     Cu_exp_u_beta = Cu * exp(u * beta);
  //     C1 += Cu_exp_u_beta;
  //     Cu_exp_u_beta *= (ti-u);
  //     C2 += Cu_exp_u_beta;
  //     Cu_exp_u_beta *= (u*beta);
  //     C3 += Cu_exp_u_beta;
  // }
  // C4 = ti *C1 - C2;
  // mpf_class mpf_fbeta = C * exp(ti*beta) / C1;
  // mpf_class mpf_fbetap = mpf_fbeta * C2 / C1;
  // mpf_class mpf_fbetapp = mpf_fbetap * C2 / C1 + fbeta * (C3*C1 - C2*C4)/C1/C1;
  // fbeta = mpf_fbeta.get_d();
  // fbetap = mpf_fbetap.get_d();
  // fbetapp = mpf_fbetapp.get_d();

  return ;
};
double ExactLogisticRegression::NewtonRalphsonStep(double oldX, double fX, double fpX) {
  if (fabs(fpX) < 1e-6) {
    std::cout << "Warning: Dividing small number in Newton-Ralphson algorithm at " << __FILE__<<":"<<__LINE__<<std::endl;
  }
  double newX;
  newX = oldX - fX / fpX;
  return newX;
};
// adjust:
//   true: when the standard Newton-Ralphson does not converge, we calculate f(beta) == 1/2 (need to set @param adjustValue = 0.5)
//   false: using typical Newton-Ralphson method to find beta that maximize f(beta)
double ExactLogisticRegression::NewtonRalphson(int nStep, bool adjust, const double adjustValue ) {
  int step = 0;
  double old_beta = 0.0;
  double new_beta = 0.0;
  double fbeta, fbetap, fbetapp;
  while (step ++ <= nStep) {
    CalculateFBeta(fbeta, fbetap, fbetapp, old_beta);
    if DEBUG std::cout << "step "<< step << " beta="<<old_beta << std::endl;
    std::cout << "step "<< step << " beta= "<<old_beta << std::endl;    
    if (adjust) {
      fbeta -= adjustValue;
      new_beta = NewtonRalphsonStep(old_beta, fbeta, fbetap);
    } else{
      new_beta = NewtonRalphsonStep(old_beta, fbetap, fbetapp);
    }
    if (fabs(old_beta - new_beta) < 1e-5) break;
    if (fabs(new_beta < 1e-20)) return new_beta;
    old_beta = new_beta;
  }
  return new_beta;
};

void ExactLogisticRegression::printStage(StageType& st) {
  for (StageTypeIter it = st.begin(); it < st.end(); it++) {
    for (std::vector<int>::iterator iit = (*it).stat.begin() ; iit < (*it).stat.end(); iit++) {
      if (iit != (*it).stat.begin())
        std::cout << ",";
      std::cout<< (*iit);
    }
    std::cout<<"(";
    std::cout<<(*it).freq;
    std::cout<<") ; ";
  }
  std::cout<< std::endl;
};

#ifdef INCLUDE_LIBSTATGEN
// condXindex will be used for inference
int ExactLogisticRegression::FitModel(Matrix& X, Vector& Y, int maxRound, int betaIdx){
  // push response
  int len = Y.Length();
  std::vector<int> v (len);
  for (int i = 0; i < len; ++i)
  {
    v[i] = Y[i];
  }
  PushResponse(v);

  // push predictor
  assert(X.rows == len);
  assert( betaIdx < X.rows);

  for (int col = 0; col < X.cols; col++) {
    v.clear();
    if (col == betaIdx) continue; // push that column at the end;
    for (int row = 0; row < len; row++) {
      v.push_back(X[row][col]);
    }
    PushPredictor(v);
  }
  v.clear();
  for (int row = 0; row < len; row++) {
    v.push_back(X[row][betaIdx]);
  }
  PushPredictor(v);
  this->p = X.cols - 1;
  this->q = 1;

  init(this->p , this->q);
  iterate(maxRound);

  return 0;
};
#endif
int ExactLogisticRegression::FitModel(const std::vector<int>& genotype,
                                      const std::vector<int>& phenotype,
                                      int maxRound){
  assert(genotype.size() == phenotype.size());

  // push response
  int len = phenotype.size();
  std::vector<int> v (len);
  PushResponse(phenotype);

  // push predictor
  for (int i = 0; i < len; ++i)
  {
    v[i] = 1;
  }
  PushPredictor(v);
  PushPredictor(genotype);
  this->p = 1;
  this->q = 1;

  init(this->p , this->q);
  iterate(maxRound);

  return 0;
};

void ExactLogisticRegression::PushResponse(const std::vector<int>& Y) {
  assert(Y.size()>=0);
  response = Y;
};
void ExactLogisticRegression::PushPredictor(const std::vector<int>& X) {
  assert(X.size()>=0);
  predictor.push_back(X);
};
void ExactLogisticRegression::tempLoad() {
  int succ[] = {0, 0, 0, 0, 1, 2};
  int fail[] = {3, 3, 3, 3, 2, 1};
  int dose[] = {0, 1, 2, 3, 4, 5};

  std::vector<int> response;
  std::vector<int> predictor_dose;
  std::vector<int> predictor_int;
  for (int i = 0; i < 6; i++){
    for (int total = 0; total < succ[i]+fail[i]; total++) {
      if (total < succ[i]) response.push_back(1);
      else response.push_back(0);
      predictor_dose.push_back(dose[i]);
      predictor_int.push_back(1);
    }
  }
  PushResponse(response);

  PushPredictor(predictor_int);
  PushPredictor(predictor_dose);

}
