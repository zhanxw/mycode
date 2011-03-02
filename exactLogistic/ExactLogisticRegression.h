#ifndef _EXACTLOGISTICREGRESSION_H_
#define _EXACTLOGISTICREGRESSION_H_
#include <vector>
#include <gmpxx.h>

class StringIntHashMap;
class DistributionType{
public:
    DistributionType(): freq(0) {};
    DistributionType(int num, int val):freq(num), vec(num-1, val) {};
public:
    mpz_class freq;
    std::vector<int> vec; // t_1, t_2, ...
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
    double NewtonRalphson(int nStep, bool adjust = false);
private:
    void printStage(StageType& st);
public:
    // 0-based condXindex column of X will be used for inference
    // P(t_1, t_2, ..., t_{condXindex-1}, t_{condXindex+1}, ... t_{p+q} |x_{condXindex}) 
    // distribution will be used for inference
    int FitModel(Matrix& X, Vector& Y, int maxRound, int condXindex); 
    double GetExactPvalue() {return this->pvalue;};
    double GetBetaEstimate() {return this->beta; };
    double GetConditionalDist() { 
        std::cout << "(freq, t_1, t_2, ..., t_{i-1}, t_{i+1}, ... ,t_{p}, t_{p+q} ) " ;
        std::cout << std::endl;
        printStage(this->currentStage); }
private:
    void PushResponse(std::vector<int>& Y);
    void PushPredictor(std::vector<int>& X);
private:
    void tempLoad();
private:
    StageType currentStage;
    int p; // number of nuisance params
    int q; // number of interested params, only q=1 is supported for now.
    std::vector<int> response;
    std::vector<std::vector<int> > predictor;
    int realizationPos; // index in currentStage, indicating where the realization locates
    double pvalue; // exact pvalue result
    double beta;   // exact beta estimation
};

#endif /* _EXACTLOGISTICREGRESSION_H_ */
