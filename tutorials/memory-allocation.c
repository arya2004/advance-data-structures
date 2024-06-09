#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;  // Initialize a pointer to int
    int size = 5;     // Initial size of the array

    // Allocate memory for the initial array
    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Calculate the number of elements in the array
    int num_elements = sizeof(arr) / sizeof(arr[0]);

    // Initialize the array
    for (int i = 0; i < num_elements; i++) {
        arr[i] = i * 10;
    }

    // Print the number of elements
    printf("Number of elements in the array (initial): %d\n", num_elements);

    // Reallocate memory to increase the size of the array
    int newSize = 10;
    arr = (int *)realloc(arr, newSize * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return 1;
    }

    // Update the number of elements after reallocating
    num_elements = sizeof(arr) / sizeof(arr[0]);

    // Initialize the additional elements
    for (int i = size; i < num_elements; i++) {
        arr[i] = i * 10;
    }

    // Print the number of elements after reallocating
    printf("Number of elements in the array (after reallocating): %d\n", num_elements);

    // Free the allocated memory
    free(arr);

    return 0;
}
