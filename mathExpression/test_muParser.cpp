/**
 * muParser
 * muparser.sourceforge.net/
 */

#include <stdio.h>
#include <stdlib.h>

#include "software/muparser_v2_2_2/include/muParser.h"

double checkExpression(const char* formular, double gq, double dp) {
    mu::Parser p;
    p.DefineVar("GQ", &gq);
    p.DefineVar("DP", &dp);

    p.SetExpr(formular);
    
    double res = p.Eval();
    return res;
};


int main(int argc, char *argv[])
{
    FILE* fp = fopen("test.txt", "r");
    double gq;  /// not support int type
    double dp;
    double div;

    printf("GQ\tDP\tGQ+DP\tGQ/DP\tGD>DP\n");
    while (fscanf(fp, "%lf %lf %lf", &gq, &dp, &div) != EOF) {
        printf("%lf\t%lf\t%lf", gq, dp, div);
        printf("\t%lf", checkExpression("GQ + DP", gq, dp));
        printf("\t%lf", checkExpression("GQ / DP", gq, dp));
        printf("\t%lf", checkExpression("GQ > DP", gq, dp));
        printf("\n");
    }

    fclose(fp);
    return 0;
}
