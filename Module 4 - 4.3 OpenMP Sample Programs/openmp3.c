#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main() {
    int n = 1000000;  // Size of the array
    int *arr = (int*) malloc(n * sizeof(int));
    long long sum = 0;

    // Initialize the array with values
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  // Just for demonstration, 1, 2, 3, ..., n
    }

    // Set the number of threads to use (you can modify this as needed)
    int num_threads = 4; // Set the number of threads you want to use
    omp_set_num_threads(num_threads);  // Set the number of threads for OpenMP

    // Print the number of threads being used by OpenMP
    int actual_threads = omp_get_max_threads();
    printf("OpenMP is using %d threads.\n", actual_threads);

    // Start timing the parallel sum computation using clock()
    double start_time = omp_get_wtime();  // Start time for OpenMP

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // End timing using omp_get_wtime()
    double end_time = omp_get_wtime();  // End time for OpenMP
    double elapsed_time = end_time - start_time;

    // Output the sum and the time taken
    printf("Sum: %lld\n", sum);
    printf("Time taken: %f seconds\n", elapsed_time);

    // Free the memory
    free(arr);

    return 0;
}

