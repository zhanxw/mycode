/**
 * muParserX
 * code.google.com/p/muparserx
 */

#include <stdio.h>
#include <stdlib.h>

#include "software/muparserx-read-only/parser/mpParser.h"
using namespace mup;

double checkExpression(const char* formular, double gq, double dp) {
    ParserX p(pckALL_NON_COMPLEX);
    Value v_gq(gq);
    Value v_dp(dp);
    
    p.DefineVar("GQ", Variable(&v_gq));
    p.DefineVar("DP", Variable(&v_dp));

    p.SetExpr(formular);
    
    Value res = p.Eval();
    return res.GetFloat();
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
