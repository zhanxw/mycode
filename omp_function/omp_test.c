#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // omp_set_num_threads(12); that affectsomp_get_max_threads()
    printf("omp_get_num_threads() [default value] = %d\n", omp_get_num_threads());
    printf("omp_get_max_threads() = %d \n", omp_get_max_threads());
    printf("omp_get_num_procs() = %d\n", omp_get_num_procs());
    printf("omp_get_wtime() = %f\n", omp_get_wtime() );
    printf("omp_get_wtick() = %f\n", omp_get_wtick() );
    return 0;
}
