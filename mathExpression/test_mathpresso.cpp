#include <stdio.h>
#include <stdlib.h>

#include "software/mathpresso/MathPresso/MathPresso.h"

double checkExpression(const char* formular, double gq, double dp) {
    MathPresso::Context ctx;
    MathPresso::Expression expression;

    MathPresso::mreal_t var[2];
    var[0] = gq;
    var[1] = dp;
    
    const char* names[] = {"GQ", "DP"};

    ctx.addEnvironment(MathPresso::MENVIRONMENT_ALL);
    ctx.addVariable("GQ", 0 * sizeof(MathPresso::mreal_t));
    ctx.addVariable("DP", 1 * sizeof(MathPresso::mreal_t));

    if (expression.create(ctx, formular) != MathPresso::MRESULT_OK) {
        printf("Error compiling expression! \n%s\n", formular);
    } else {
        return expression.evaluate(var);
    };
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
