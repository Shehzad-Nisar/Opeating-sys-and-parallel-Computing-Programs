#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main() {
    int n = 1000000;  // size of the array
    int *arr = (int*) malloc(n * sizeof(int));
    long long sum = 0;

    // Initialize the array with values
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  // Just for demonstration, 1, 2, 3, ..., n
    }

    // Start timing the parallel sum computation
    double start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // End timing
    double end_time = omp_get_wtime();
    double elapsed_time = end_time - start_time;

    // Output the sum and the time taken
    printf("Sum: %lld\n", sum);
    printf("Time taken: %f seconds\n", elapsed_time);

    // Free the memory
    free(arr);
    return 0;
}

