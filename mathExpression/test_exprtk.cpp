/**
 * C++ mathematical expression library
 * http://www.partow.net/programming/exprtk/index.html
 */

#include <stdio.h>
#include <stdlib.h>
#include "software/exprtk/exprtk.hpp"

#include <string>

template<typename T>
T checkExpression(const char* formular, T gq, T dp) {
    std::string expression_string = formular;
    T x;
    exprtk::expression<T> expression;
    exprtk::symbol_table<T> symbol_table;
    symbol_table.add_variable("GQ", gq);
    symbol_table.add_variable("DP", dp);
    symbol_table.add_constants();
    expression.register_symbol_table(symbol_table);
    exprtk::parser<T> parser;
    parser.compile(expression_string, expression);
    
    T res = expression.value();
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
