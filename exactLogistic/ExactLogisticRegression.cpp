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

// skip: how many elements to skip (including the first one (freq))
std::string toString(DistributionType& v, int skip = 0) {
    std::stringstream oss;
    if (skip == 0 ) {
        oss << v.freq;
        oss << ',';
    }
    skip -- ;
    for (std::vector<int>::iterator it = v.vec.begin(); it < v.vec.end(); it++) {
        if (skip > 0 ) { skip--; continue; }
        oss << *it;
        oss << ',';
    }
    return oss.str();
}

std::string toString(std::vector<int>& v, int skip = 0) {
    std::stringstream oss;
    for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        if (skip > 0 ) { skip--; continue; }
        oss << *it;
        oss << ',';
    }
    return oss.str();
}

// Hashmap:
// key: string
// value: index position (>=0), -1 means unfound
class StringIntHashMap {
public:
    int find(std::string& s) {
        if (tupleToPosMap.find(s) != tupleToPosMap.end()) {
            return tupleToPosMap[s];
        } else {
            return -1;
        }
    };
public:
    int& operator[] (const std::string&s) {
        return tupleToPosMap[s];
    };
public:
    void clear() {tupleToPosMap.clear();};
private:
    std::tr1::unordered_map<std::string, int> tupleToPosMap;

#if 0
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    string s;
    s = toString(v);
    tupleToPosMap[s] = 12;
    if (tupleToPosMap.find(s) != tupleToPosMap.end()) {
        std::cout << s << " found at pos " << tupleToPosMap[s] <<std::endl;
    } else {
        std::cout <<s << " not found "<< std::endl;
    }

    v.push_back(3);
    s = toString(v);
    if (tupleToPosMap.find(s) != tupleToPosMap.end()) {
        std::cout << s << " found at pos " << tupleToPosMap[s] <<std::endl;
    } else {
        std::cout <<s << " not found "<< std::endl;
    }
#endif

};


ExactLogisticRegression::ExactLogisticRegression(){};
void ExactLogisticRegression::init(int p, int q){
    this->p = p ;
    this->q = q ;
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
int ExactLogisticRegression::iterate(int maxRound) {
    // calculate realization
    int nSample = response.size();
    std::vector<int> t(p+q,0);
    for (int stage = 1; stage <= nSample; stage++) {
        for (int i = 0; i < p+q ; i++) {
            t[i] += response[stage-1] * predictor[i][stage-1];
        }
    }

    // Multivariate-shift algorithm
    // Detail:
    //   base on currentStage, we put results to nextStage (refer to the SAS paper we calculate layer by layer)
    //   then we assign current stage from nextStage
    //   after all stages are process, the results are stored in the currentStage
    std::string key; // used as hash key
    StringIntHashMap posHash;
    StageType nextStage;

    for (int stage = 1; stage <= nSample; stage++) {
        if DEBUG std::cout << "Stage "<< stage<< std::endl;
        posHash.clear();
        nextStage.clear();
        for (StageTypeIter it = currentStage.begin(); it < currentStage.end(); it++) {
            // algorithm
            // calculate new statistics for y_{i+1}
            // todo: check if it is feasible
            // check pos
            // push it to the nextStage
            //
            //   when y_{i+1} = 0
            key = toString(*it, 1);
            if (posHash.find(key) >= 0) {
                int pos = posHash[key];
                nextStage[pos].freq += (*it).freq;
            } else {
                posHash[key] = nextStage.size();
                nextStage.push_back(*it);
            }
            // when y_{i+1} = 1
            //std::vector<int> v (*it);
            DistributionType v;
            v.freq = (*it).freq;
            v.vec = (*it).vec;
            for (int i = 0; i < (p+q); i++ ) {
                v.vec[i] += predictor[i][stage-1];
            }
            key = toString(v, 1);
            if (posHash.find(key) >= 0) {
                int pos = posHash[key];
                nextStage[pos].freq += (*it).freq;
            } else {
                posHash[key] = nextStage.size();
                nextStage.push_back(v);
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

        currentStage = nextStage;
        // output current stage
        if DEBUG printStage(currentStage);

    } // for stage


    // find the realization position
    key = toString(t);
    this->realizationPos = posHash[key];

    // filter useless contrains and obtain conditional dist.
    mpz_class c_t1_t0 = currentStage[realizationPos].freq; //C(t1, t0) ; frequncy of counts that generates realization
    mpz_class c_t =  0;  // C(t); # of more extreme case than c_t1_t0
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
            if ( (*iter).vec[i] != t[i]) {
                passed = false;
                break;
            }
        }
        // T0 = t0 cases
        if (passed) {
            if ( (*iter).freq <= c_t1_t0)
                c_t += (*iter).freq;
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
    currentStage = nextStage;
    assert(this->realizationPos < currentStage.size());
    // output current stage
    // printStage(currentStage);

    mpz_class tmp_pvalue = 1e6 * c_t / c_u_t; // 1e6: to avoid convert mpz_class to mpf_class (integer to float)
    this->pvalue = 1e-6 * ( tmp_pvalue.get_d());// ( c_t /c_u_t );
    if DEBUG std::cout << "exact p-value = " << c_t<<" "<< c_u_t<< " "<< this->pvalue << std::endl;

    // output exact estimate of beta
    if (currentStage[this->realizationPos].freq == tmp_min_freq ||
        currentStage[this->realizationPos].freq == tmp_max_freq)
    {
        // when realization is the min/max freq, Newton-Ralphson won't converge (refer: SAS paper)
        // we will solve f(betai) = 1/2
        std::cerr << "Warning: beta_estimation is adjusted" << std::endl;
        this->beta = NewtonRalphson(100, true);
    }  else {
        // we use Newton-Ralphson to maximize f(betai)
        this->beta = NewtonRalphson(100, false);
    }
    if DEBUG std::cout << "beta = " << beta << std::endl;

    return 0;
};

void ExactLogisticRegression::CalculateFBeta(double& fbeta, double& fbetap, double& fbetapp,  // p: derivative
                                             double beta) {
    mpf_class C1 = 0.0;
    mpf_class C2 = 0.0;
    mpf_class C3 = 0.0;
    mpf_class C4 = 0.0;

    int qIndex = currentStage[this->realizationPos].vec.size() - 1;
    mpf_class C = currentStage[this->realizationPos].freq;
    double ti = currentStage[this->realizationPos].vec[qIndex];

    mpf_class Cu;
    mpf_class Cu_exp_u_beta;
    for (StageTypeIter iter = currentStage.begin(); iter < currentStage.end(); iter++ ) {
        Cu = (*iter).freq;
        double u = (*iter).vec[qIndex];
        Cu_exp_u_beta = Cu * exp(u * beta);
        C1 += Cu_exp_u_beta;
        Cu_exp_u_beta *= (ti-u);
        C2 += Cu_exp_u_beta;
        Cu_exp_u_beta *= (u*beta);
        C3 += Cu_exp_u_beta;
    }
    C4 = ti *C1 - C2;
    mpf_class mpf_fbeta = C * exp(ti*beta) / C1;
    mpf_class mpf_fbetap = mpf_fbeta * C2 / C1;
    mpf_class mpf_fbetapp = mpf_fbetap * C2 / C1 + fbeta * (C3*C1 - C2*C4)/C1/C1;
    fbeta = mpf_fbeta.get_d();
    fbetap = mpf_fbetap.get_d();
    fbetapp = mpf_fbetapp.get_d();

    return ;
};
double ExactLogisticRegression::NewtonRalphsonStep(double oldX, double fX, double fpX) {
    if (fabs(fpX) < 1e-6) {
        std::cout << "Warning in Newton-Ralphson algorithm at " << __FILE__<<":"<<__LINE__<<std::endl;
    }
    double newX;
    newX = oldX - fX / fpX;
    return newX;
};
// adjust:
//   true: when the standard Newton-Ralphson does not converge, we calculate f(x) == 1/2
//   false: using typical Newton-Ralphson method
double ExactLogisticRegression::NewtonRalphson(int nStep, bool adjust) {
    int step = 0;
    double old_beta = 0.0;
    double new_beta = 0.0;
    double fbeta, fbetap, fbetapp;
    while (step ++ <= nStep) {
        CalculateFBeta(fbeta, fbetap, fbetapp, old_beta);
        if DEBUG std::cout << "step "<< step << " beta="<<old_beta << std::endl;
        if (adjust) {
            fbeta -= 0.5;
            new_beta = NewtonRalphsonStep(old_beta, fbeta, fbetap);
        } else{
            new_beta = NewtonRalphsonStep(old_beta, fbetap, fbetapp);
        }
        if (fabs(old_beta - new_beta) < 1e-5) break;
        old_beta = new_beta;
    }
    return new_beta;
};


void ExactLogisticRegression::printStage(StageType& st) {
    for (StageTypeIter it = st.begin(); it < st.end(); it++) {
        std::cout<<"(";
        std::cout<<(*it).freq<<", ";
        for (std::vector<int>::iterator iit = (*it).vec.begin() ; iit < (*it).vec.end(); iit++) {
            std::cout<< (*iit) << ", " ;
        }
        std::cout<<") ; ";
    }
    std::cout<< std::endl;
};

// condXindex will be used for inference
int ExactLogisticRegression::FitModel(Matrix& X, Vector& Y, int maxRound, int condXindex){
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
    assert( condXindex < X.rows);

    for (int col = 0; col < X.cols; col++) {
        v.clear();
        if (col == condXindex) continue; // push that column at the end;
        for (int row = 0; row < len; row++) {
            v.push_back(X[row][col]);
        }
        PushPredictor(v);
    }
    v.clear();
    for (int row = 0; row < len; row++) {
        v.push_back(X[row][condXindex]);
    }
    PushPredictor(v);
    this->p = X.cols - 1;
    this->q = 1;

    init(this->p , this->q);
    iterate(maxRound);

    return 0;
};

void ExactLogisticRegression::PushResponse(std::vector<int>& Y) {
    assert(Y.size()>=0);
    response = Y;
};
void ExactLogisticRegression::PushPredictor(std::vector<int>& X) {
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

