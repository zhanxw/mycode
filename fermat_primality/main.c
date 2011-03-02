#ifdef _OPENMP
#pragma message "Use OPENMP"
#include <omp.h>
#endif
#include <stdio.h>
#include <stdlib.h>


// get a^p mod n
int pow_mod(int a, int n, int p){
    if (p == 1) {
        return a;
    }
    int half_p = p/2;
    int q = p%2;
    int t;
//#pragma omp task shared(t)
    t = pow_mod(a, n, half_p);
    int r = (t*t) %n;
//#pragma omp taskwait
    if (q==0)
        return r;
    else 
        return ((r*a)%n);
}

void fermat_test(const int n, int* p, int* np) {
    *p = *np = 0;
    int a;
#pragma omp parallel for private(a)
    for ( a=2; a < n; a++) {
        if ( pow_mod(a, n, n) == a)
            *p += 1;
        else
            *np +=1;
    }

}

int main(int argc, char *argv[])
{
    int max = atoi(argv[1]);

#ifdef _OPENMP
    omp_set_num_threads(8);
#endif

    int passed, not_passed;
#pragma omp parallel for private(passed, not_passed) num_threads(4)
    for (int  n = 3; n < max; n++) {        
        passed = not_passed = 0;
        fermat_test(n, &passed, &not_passed);
        printf("%d\t%d\t%d\t%f\n", n, passed, not_passed, 1.0*passed/(passed+not_passed));
    }
    return 0;
}
