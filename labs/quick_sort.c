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


// Function to swap two Student struct

void swap(Student* a, Student* b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array for quicksort
int partition(Student* arr, int l, int h)
{
    float pivot = arr[l].CPI;
    int i = l;
    int j = h;

    while (i < j) {
        while (arr[i].CPI <= pivot && i < h) {
            i++;
        }

        while (arr[j].CPI > pivot) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[l], &arr[j]);

    return j;
}

// Recursive function to perform quick sort
void quicksort(Student* arr, int l, int h)
{
    if (l < h) {
        int j = partition(arr, l, h);
        quicksort(arr, l, j - 1);
        quicksort(arr, j + 1, h);
    }
}
