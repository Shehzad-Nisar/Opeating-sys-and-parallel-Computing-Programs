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

    // Start timing the parallel sum computation using clock()
    clock_t start_time = clock();

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // End timing using clock()
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Output the sum and the time taken
    printf("Sum: %lld\n", sum);
    printf("Time taken: %f seconds\n", elapsed_time);

    // Free the memory
    free(arr);
    return 0;
}

