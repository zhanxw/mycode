#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <math.h>

#include "debug.h"
#include "timing.h"

// shuffle an array using Fisher-Yate's method
void inplace_shuffle(double * data, int n) {
    int j;
    double temp;
    for (int i = n-1; i > 0; i--) {
        j  = rand() % i ;
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

typedef struct vec_s {
    double* value;
    unsigned int cap; 
    unsigned int len;
} vec_t, *vec_p;

vec_p vector_new(int cap) {
    vec_p vec;
    vec = malloc(sizeof(vec_t));
    assert(vec);
    vec->value = malloc(sizeof(double)*cap);
    assert(vec->value);
    vec->len = 0; 
    vec->cap = cap;

    return vec;
}

void vector_delete(vec_p* p_vec) {
    assert(p_vec);
    vec_p vec = *p_vec;

    assert(vec && vec->value);
    free(vec->value);
    free(vec);
    vec = NULL;
    return;
}

vec_p vector_grow(vec_p vec, int cap) {
    assert(cap > 0);
    double* p = realloc(vec->value, sizeof(double)*cap);
    assert(p);

    vec->value = p;
    vec->cap = cap;
    return vec;
}

void vector_print(vec_p vec) {
    for (int i = 0; i< vec->len; i++) {
        printf("%f\t", vec->value[i]);
    }
    printf("Len=%d\tCap=%d\n", vec->len, vec->cap);
    return;
}

int vector_read(vec_p vec, const char* filename) {
    assert(vec);
    assert(vec->len == 0);
    FILE* fp;
    double r;
    int ret;
    fp = fopen(filename, "r");
    if(!fp) {
        printf("Cannot open %s\n", filename);
        exit(1);
    }
                                                
    //double temp;
    char temp[128];
    while (!feof(fp)) {
        if (vec->len == vec->cap) {
            vector_grow(vec, vec->cap * 2);
        }
        ret = fscanf(fp, "%s", temp);
        if (ret == EOF) break;
        PINT(vec->len);
        errno = 0;
        vec->value[vec->len++] = strtod(temp, NULL);
        //vector_print(vec);
        if (errno != 0) {
            perror("strtod");
            fprintf(stderr, "%s\n", temp);
            exit(EXIT_FAILURE);
        }
    }
    fclose(fp);
    return vec->len;
}

double vector_corr(vec_p x, vec_p y) {
    double ret = 0.0;
    assert(x->len == y->len && x->len > 0);
    
    double xmean = 0.0, ymean = 0.0;
    for (int i = 0; i < x->len; i++){
        xmean += x->value[i];
        ymean += y->value[i];
    }
    xmean /= x->len;
    ymean /= x->len;

    double xstd = 0.0, ystd = 0.0, xycov = 0.0;
    double tempx, tempy;
    for (int i = 0; i < x-> len; i++) {
        tempx = (x->value[i] - xmean);
        tempy = (y->value[i] - ymean);
        xstd += tempx*tempx;
        ystd += tempy*tempy;
        xycov += tempx * tempy;
    }
    return xycov / sqrt(xstd * ystd);
}

/**
 * permutate Y, calculate the correlation between Y and X 
 * store results in result
 * NOTE: x, y content will be changed.
 */
void vector_corr_permutation(vec_p x, vec_p y, 
                               double* result, 
                               unsigned int nPerm) {
    double ret = 0.0;
    assert(x->len == y->len && x->len > 0);
    
    double xmean = 0.0, ymean = 0.0;
    for (int i = 0; i < x->len; i++){
        xmean += x->value[i];
        ymean += y->value[i];
    }
    xmean /= x->len;
    ymean /= x->len;

    double xstd = 0.0, ystd = 0.0, xycov = 0.0;
    double tempx, tempy;
    for (int i = 0; i < x-> len; i++) {
        
        x->value[i] -= xmean;
        y->value[i] -= ymean;
        xstd += x->value[i] * x->value[i];
        ystd += y->value[i] * y->value[i];
    }

    for (int n = 0; n < nPerm; n++ ) {
        inplace_shuffle(y->value, y->len);
        xycov = 0.0;
        for (int i = 0; i < x-> len; i++) {
            xycov += x->value[i] * y->value[i];
        }
        result[n] = xycov / sqrt(xstd * ystd);
    }
    return ;
}

/**
 * permutate Y, calculate the correlation between Y and X 
 * store results in result
 * NOTE: x, y content will be changed.
 */
#include "mkl.h"

void mkl_vector_corr_permutation(vec_p x, vec_p y, 
                               double* result, 
                               unsigned int nPerm) {
    double ret = 0.0;
    assert(x->len == y->len && x->len > 0);
    
    double xmean = 0.0, ymean = 0.0;
    for (int i = 0; i < x->len; i++){
        xmean += x->value[i];
        ymean += y->value[i];
    }
    xmean /= x->len;
    ymean /= x->len;

    /* vec_p temp; */
    /* temp = vector_new (x->len); */

    double xstd = 0.0, ystd = 0.0, xycov = 0.0;
    double tempx, tempy;
    for (int i = 0; i < x-> len; i++) {
        
        x->value[i] -= xmean;
        y->value[i] -= ymean;
    }
    xstd = sqrt(cblas_dnrm2(x->len, x->value, 1));
    ystd = sqrt(cblas_dnrm2(x->len, y->value, 1));

    for (int n = 0; n < nPerm; n++ ) {
        inplace_shuffle(y->value, y->len);
        xycov = 0.0;
        xycov = cblas_ddot(x->len, x->value, 1, y->value, 1);
        result[n] = xycov / sqrt(xstd * ystd);
    }
    return ;
}

void usage(const char* prog) {
    fprintf(stderr, "%s shuffle_time input_X inputY\n", prog);
}

int main(int argc, char *argv[])
{
    //////////////////////////////////////////////////////////////////////
    // Handel argument
    if (argc != 4) {
        usage(argv[0]);
        exit(1);
    }
    const unsigned int shuffle_time = atof(argv[1]);
    const char* inputX = argv[2];
    const char* inputY = argv[3]; 

    debug_level_set(SILENT);
    printf("begin allocating memory:\n");
    vec_p x, y;
    x = vector_new(4);
    y = vector_new(4);

    printf("begin read:\n");
    vector_read(x, inputX);
    vector_read(y, inputY);
    // vector_print(x);

    double* ret = malloc(sizeof(double)*shuffle_time);
    assert(ret);

    
    //////////////////////////////////////////////////////////////////////
    // Method 1
    // parallel this part
    timing_start();
    for (int i = 0; i < shuffle_time; i++) {
        inplace_shuffle(y->value, y->len);
        ret[i] = vector_corr(x,y);
    }
    timing_stop();
    timing_diff();

    //////////////////////////////////////////////////////////////////////
    // Method 2
    timing_start();
    vector_corr_permutation(x, y, ret, shuffle_time);
    timing_stop();
    timing_diff();

    //////////////////////////////////////////////////////////////////////
    // Method 3
    timing_start();
    mkl_vector_corr_permutation(x, y, ret, shuffle_time);
    timing_stop();
    timing_diff();



    exit(0);
    // output result
    printf("Result\n");

    for (int i = 0; i < shuffle_time; i++) {
        printf("%f\n", ret[i]);
    }

    vector_delete(&x);
    vector_delete(&y);
    free(ret);
    return 0;
    
}
