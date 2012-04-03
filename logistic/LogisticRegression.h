//////////////////////////////////////////////////////////////////////
// Adopted by Xiaowei Zhan 
// 
// mach2dat/LogisticRegression.h
// (c) 2008 Yun Li
//
// March 15, 2008
//

#ifndef __LOGISTIC_REGRESSION_H__
#define __LOGISTIC_REGRESSION_H__

#include "MathMatrix.h"
#include "MathCholesky.h"
#include "StringHash.h"
#include "StringArray.h"
#include <cmath>

class Pedigree;

class LogisticRegression
{
public:
    LogisticRegression();
    ~LogisticRegression();

    bool FitLogisticModel(Matrix & X, Vector & y, int rnrounds); // return false if not converging
    bool FitLogisticModel(Matrix & X, Vector & succ, Vector& total, int nrrounds);
    double GetDeviance(Matrix & X, Vector & y);
    double GetDeviance(Matrix & X, Vector & succ, Vector& total);
	Vector & GetAsyPvalue();
	Vector & GetCovEst();
	Matrix & GetCovB();
    void reset(Matrix& X); // get everything cleared
	
    Vector B;       // coefficient vector
    Matrix covB;    // coefficient covariance matrix
	
private:
	Vector pValue;
	Vector p, V, W;
    Vector residuals;
    Vector deltaB;
    Matrix D;
	Matrix testSummary;
    Matrix Dinv;
    Cholesky chol;
    Matrix Dtwo;
	Matrix XtV;

};

class LogisticRegressionScoreTest{
public:
LogisticRegressionScoreTest():pvalue(0.0){};
    bool FitLogisticModel(Matrix &X, Vector &y, int colToTest, int nRound) {
        Matrix Xnull;
        Vector xcol;
        this->splitMatrix(X, colToTest, Xnull, xcol);
        LogisticRegression lr;
        if (lr.FitLogisticModel(Xnull, y, nRound) == false){
            return false;
        }
        Vector & betaHat = lr.GetCovEst(); // From MLE
        double U = 0.0;
        double I = 0.0;
        for (int i = 0; i < X.rows; i++){
            double bnull = 0.0;
            for (int j = 0; j < X.cols; j++){
                if (j == colToTest) continue;
                bnull += X[i][j] * betaHat[j];
            }
            bnull = exp(bnull);
            U += xcol[i] * (bnull*(-1.0+y[i])+y[i]) / (1.0 + bnull);
            double tmp = xcol[i]/(1.0+bnull);
            I += bnull* tmp * tmp;
            printf("i=%d U=%.3f I=%.3f\n", i, U, I);
        }
        this->pvalue = U*U/I;
    }
    double getPvalue() const {return this->pvalue;};
private:
    void splitMatrix(Matrix& x, int col, Matrix& xnull, Vector& xcol){
        if (x.cols < 2) {
            printf("input matrix has too few cols!\n");
        }
        xnull.Dimension(x.rows, x.cols - 1);
        xcol.Dimension(x.rows);
        for (int i = 0; i < x.rows; i++){
            for (int j = 0; j < x.cols; j++){
                if (j < col){
                    xnull[i][j] = x[i][j];
                }else if (j == col){
                    xcol[i] = x[i][j];
                } else {
                    xnull[i][j-1] = x[i][j];
                }
            }
        }
    };
    double pvalue;
};
#endif



