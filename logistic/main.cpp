#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MathMatrix.h"
#include "MathVector.h"
#include "LogisticRegression.h"
#include "InputFile.h"

int loadMatrix(Matrix& a, String& fileName);
int loadVector(Vector& a, String& fileName);

int main(int argc, char *argv[])
{
    time_t now  = time(0);
    printf("Start analysis at %s \n", ctime(&now));

    Matrix X;
    String Xinput = "ExampleX";
    Vector Y;
    String Yinput = "ExampleY";

    if (loadMatrix(X,Xinput) || loadVector(Y, Yinput)) {
        fprintf(stderr, "Data loading problem!\n");
        exit(1);
    }

    LogisticRegression lr;
    if (lr.FitLogisticModel(X, Y, 15) ) {
        printf("fit all right!\n");
    } else {
        printf("fit failed\n");
    }
    now = time(0);
    printf("Finsihed analysis at %s \n", ctime(&now));

    LogisticRegressionScoreTest lrst;
    int Xcol = 1;
    lrst.FitLogisticModel(X,Y,Xcol,100);
    printf("score p-value is: %lf \n", lrst.getPvalue());
    Vector& pvalue = lr.GetAsyPvalue();
    printf("wald p-value is: %lf \n", pvalue[Xcol]);
    return 0;
}


int loadMatrix(Matrix& a, String& fileName) {
    a.Zero();

    IFILE ifile(fileName.c_str(), "r");
    String line;
    StringArray array;
    int lineNo = 0;
    while (!ifeof(ifile)){
        line.ReadLine(ifile);
        lineNo ++ ;
        if (line.Length() == 0) continue;
        array.Clear();
        array.AddTokens(line);
        if (a.cols != 0 && a.cols != array.Length() && line.Length() > 0) {
            fprintf(stderr, "Wrong column size at line %d!\n", lineNo);
            array.Print();
            line.Write(stdout);
            return -1;
        } else {
            a.GrowTo(a.rows, array.Length());
        }
        if (a.rows < lineNo) {
            a.GrowTo(a.rows+1, a.cols);
        }
        for (int i = 0; i < array.Length(); i++) {
            a[lineNo-1][i] = atol(array[i]);
        }
    }
    
    // a.Print(stdout);
    return 0;
};

int loadVector(Vector& a, String& fileName) {
    a.Zero();

    IFILE ifile(fileName.c_str(), "r");
    String line;
    StringArray array;
    int lineNo = 0;
    while (!ifeof(ifile)){
        line.ReadLine(ifile);
        lineNo ++ ;
        if (line.Length() == 0) continue;
        array.Clear();
        array.AddTokens(line);
        if (array.Length() > 1 && line.Length() > 0) {
            fprintf(stderr, "Warning: column size at line %d!\n", lineNo);
            array.Print();
            line.Write(stdout);
            return -1;
        } 
        if (a.dim < lineNo) {
            a.GrowTo(a.dim+1);
        }
        a[lineNo-1] = atol(array[0]);
    }
    
    // a.Print(stdout);

    return 0;
};

