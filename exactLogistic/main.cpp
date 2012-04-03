// #include <stdio.h>
// #include <stdlib.h>
#include <iostream>
#include <ctime>

#include "InputFile.h"
#include "StringArray.h"
#include "MathMatrix.h"
#include "MathVector.h"
#include "ExactLogisticRegression.h"
// #include "LogisticRegression.h"
// #include "InputFile.h"

int loadMatrix(Matrix& a, String& fileName);
int loadVector(Vector& a, String& fileName);

void test_main(); // all test codes goes here;

int main(int argc, char *argv[])
{
    ExactLogisticRegression elr;
    Matrix X;
    Vector Y;

    // String Xinput = "eg0X";
    // String Yinput = "eg0Y";
    // String Xinput = "eg1X";
    // String Yinput = "eg1Y";
    // String Xinput = "EX1";
    // String Yinput = "EY1";
    String Xinput = "ExampleX";
    String Yinput = "ExampleY";

    if (loadMatrix(X,Xinput) || loadVector(Y, Yinput)) {
        fprintf(stderr, "Data loading problem!\n");
        exit(1);
    }

    time_t now  = time(0);
    printf("Start analysis at %s \n", ctime(&now));

    if ( elr.FitModel(X, Y, 100, 1) ) {
        std::cout << "fit all right" <<std::endl;
    } else {
        std::cout << "fit failed" <<std::endl;
    }
    // elr.GetConditionalDist();
    double p = elr.GetExactPvalue();
    double beta = elr.GetBetaEstimate();
    std::cout << "Exact p-value = " << p <<std::endl;
    std::cout << "Exact beta estimate = " << beta << std::endl;

    now = time(0);
    printf("Finsihed analysis at %s \n", ctime(&now));
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

