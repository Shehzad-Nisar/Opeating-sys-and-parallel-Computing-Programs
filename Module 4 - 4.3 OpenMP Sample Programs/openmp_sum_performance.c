#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n = 100000000;  // Size of the array (1e8 for testing large enough array)
    int *arr = (int*) malloc(n * sizeof(int));
    long long sum = 0;

    // Initialize the array with values (1, 2, 3, ..., n)
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  // For simplicity, use values 1, 2, 3, ..., n
    }

    // Array of processors to test: 4, 8, 12, 16
    int num_processors[] = {4, 8, 12, 16};
    int num_tests = sizeof(num_processors) / sizeof(num_processors[0]);

    // Loop through each number of processors to test performance
    for (int i = 0; i < num_tests; i++) {
        int threads = num_processors[i];
        
        // Set the number of threads for OpenMP
        omp_set_num_threads(threads);

        // Start measuring time for summing with the specified number of threads
        double start_time = omp_get_wtime();

        // Parallel sum computation
        #pragma omp parallel for reduction(+:sum)
        for (int j = 0; j < n; j++) {
            sum += arr[j];
        }

        // Measure end time
        double end_time = omp_get_wtime();
        double elapsed_time = end_time - start_time;

        // Output the sum and the time taken for this configuration
        printf("Threads: %d, Sum: %lld, Time: %f seconds\n", threads, sum, elapsed_time);

        // Reset the sum for the next test
        sum = 0;
    }

    // Free the allocated memory
    free(arr);

    return 0;
}

