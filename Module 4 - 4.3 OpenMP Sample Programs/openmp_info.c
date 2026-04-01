#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    // Get the number of physical processors (cores) available
    int num_processors = omp_get_num_procs();
    printf("Number of processors available: %d\n", num_processors);

    // Get the maximum number of threads OpenMP can use (this is often the number of logical cores)
    int max_threads = omp_get_max_threads();
    printf("Maximum number of threads OpenMP can use: %d\n", max_threads);

    // Get the number of threads OpenMP is actually using
    int current_threads = omp_get_num_threads();
    printf("Number of threads OpenMP is currently using: %d\n", current_threads);

    // Set the number of threads (this can be done dynamically or specified)
    // For example, let's set OpenMP to use the maximum number of threads
    omp_set_num_threads(max_threads);

    // Check the number of threads OpenMP is using after setting it
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();
        if (thread_id == 0) {
            printf("Total threads being used in the parallel region: %d\n", total_threads);
        }
    }

    return 0;
}

