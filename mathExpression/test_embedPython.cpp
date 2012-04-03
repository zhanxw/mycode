/**
 * embed Python
 * http://docs.python.org/extending/embedding.html
 */

#include <stdio.h>
#include <stdlib.h>

#include <Python.h>

double checkExpression(const char* formular, double gq, double dp) {
// Get a reference to the main module.
    PyObject* main_module =
        PyImport_AddModule("__main__");

// Get the main module's dictionary
// and make a copy of it.
    PyObject* main_dict =
        PyModule_GetDict(main_module);

    char s[1024];
    sprintf(s, "GQ=%lf", gq); //, dp, formular);
    if ( 0 != PyRun_SimpleString(s) ) { // something wrong happen!
        fprintf(stderr, "\nSomething wrong in assigning GQ\n");
        return -1.;
    }
    sprintf(s, "DP=%lf", dp);
    if ( 0 != PyRun_SimpleString(s) ) { // something wrong happen!
        fprintf(stderr, "\nSomething wrong in assigning DP\n");
        return -1.;
    }

    PyObject* ret = PyRun_String(formular, Py_eval_input, main_dict, main_dict);
    if (ret == NULL) {
        PyErr_Clear();
        return -1.;
    };

    double res;
    if (PyInt_Check(ret)) {
        res = PyLong_AsLong(ret);
    } else if (PyFloat_Check(ret)) {
        res = PyFloat_AS_DOUBLE(ret);
    } else if (PyBool_Check(ret)) {
        res = ret == Py_True;
    }
    return res;
};


int main(int argc, char *argv[])
{
    Py_Initialize();

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
    Py_Finalize();
    return 0;
}
