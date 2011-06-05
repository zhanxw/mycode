#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("omp_get_num_threads() [default value] = %d\n", omp_get_num_threads());
    printf("omp_get_max_threads() = %d \n", omp_get_max_threads());
    printf("omp_get_num_procs() = %d\n", omp_get_num_procs());
    printf("\n");

    
    omp_set_num_threads(2); // that affectsomp_get_max_threads()
    #pragma omp parallel for ordered 
    for (int i = 0; i < omp_get_max_threads(); i ++) {
        printf("Thread %d of total %d thread\n", omp_get_thread_num(), omp_get_num_threads());
    }
    printf("omp_get_num_threads() = %d (Always one in the sequencial part)\n", omp_get_num_threads());


    printf("\n");
    printf("omp_get_wtime() = %f\n", omp_get_wtime() );
    printf("omp_get_wtick() = %f\n", omp_get_wtick() );
    return 0;
}
