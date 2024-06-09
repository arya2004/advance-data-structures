#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for Student
typedef struct _Student
{
    char* name;
    int roll_no;
    float CPI;
} Student;

// Function to merge two sorted subarrays into one sorted array
void merge(Student* arr, int l, int m, int r)
{
    int i, j, k;
    const int n1 = m - l + 1;
    const int n2 = r - m;

    // Create temporary arrays for the left and right subarrays
    Student L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].CPI <= R[j].CPI) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort
void mergesort(Student* arr, int l, int h)
{
    if (l < h) {
        int mid = (l + h) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}
