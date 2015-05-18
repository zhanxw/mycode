#ifndef _EXACTLOGISTICREGRESSION_H_
#define _EXACTLOGISTICREGRESSION_H_
#include <vector>
#include <gmpxx.h>

#define max(x,y) ((x)>(y)? (x):(y))
#define min(x,y) ((x)<(y)? (x):(y))

typedef mpz_class FreqType;
typedef std::vector<int> SufficientStatType;

class StringIntHashMap;
class DistributionType{
public:
DistributionType(): freq(0) {};
DistributionType(int num, int val):freq(num), stat(num-1, val) {};
  bool operator== (const DistributionType& d) const {
    return ( this->freq == d.freq && this->stat == d.stat);
  }
public:
  FreqType freq;
  SufficientStatType stat; // t_1, t_2, ...
};

// StageType contains elements
// each element has (q+1) integers
// the 0-indexed is frequency
// the 1, 2, ... , q indiced are sufficient statistics t_i
typedef std::vector<DistributionType > StageType;
typedef std::vector<DistributionType >::iterator StageTypeIter;
class ExactLogisticRegression {
public:
  ExactLogisticRegression();
private:
  void init(int p, int q);
  int iterate(int maxRound);
private:
  void CalculateFBeta(double& fbeta, double& fbetap, double& fbetapp,  // p: derivative
                      double beta);
  double NewtonRalphsonStep(double oldX, double fX, double fpX);
  double NewtonRalphson(int nStep, bool adjust, double adjustValue);
private:
  void printStage(StageType& st);
public:
#ifdef INCLUDE_LIBSTATGEN
  // 0-based betaIdx column of X will be used for ianference
  // "joint probability" (except t_{betaIdx}, all other t_i are nuisance parameter at their realization values):
  // P(t_1, t_2, ..., t_{betaIdx-1}, t_{betaIdx}, t_{betaIdx+1}, ... t_{p+q} )
  // distribution will be used for inference
  int FitModel(Matrix& X, Vector& Y, int maxRound, int betaIdx);
#endif

  int FitModel(const std::vector<int>& genotype,
               const std::vector<int>& phenotype,
               int maxRound);
  double GetExactPvalue() const {return this->pvalue;};
  double GetBetaEstimate() const {return this->beta; };
  double GetUpperCI() const {return this->upperCI; };
  double GetLowerCI() const {return this->lowerCI; };
  double GetConditionalDist() {
    printf( "(freq, t_1, t_2, ..., t_{i-1}, t_{i+1}, ... ,t_{p}, t_{p+q} ) \n") ;
    printStage(this->currentStage); }
private:
  void PushResponse(const std::vector<int>& Y);
  void PushPredictor(const std::vector<int>& X);
private:
  // for internel test purpose
  void tempLoad();
private:
  bool isFeasible(const SufficientStatType& t,
                  const SufficientStatType& u,
                  const SufficientStatType& v,
                  const SufficientStatType& tRealization) {
    // if  t + u < tRealzation or t + v > tRealzation, then return false;
    for (int i = 0; i < p + q - 1; i ++ ){
      if (t[i] + u[i] < tRealization[i] ||
          t[i] + v[i] > tRealization[i])
        return false;
    }
    return true;
  };
private:
  StageType currentStage;
  int p; // number of nuisance params
  int q; // number of interested params, only q = 1 is supported for now.
  std::vector<int> response;
  std::vector<std::vector<int> > predictor;
  int realizationPos; // index in currentStage, indicating where the realization locates
  double pvalue; // exact pvalue result
  double beta;   // exact beta estimation
  double upperCI;
  double lowerCI;
};

#endif /* _EXACTLOGISTICREGRESSION_H_ */
