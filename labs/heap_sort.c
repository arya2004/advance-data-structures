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



// Function to maintain heap property
void heapify(Student* arr, int parent, int size)
{
    int left = 2 * parent;
    int right = (2 * parent) + 1;
    int largest = parent;

    if (left < size && arr[parent].CPI < arr[left].CPI) {
        largest = left;
    }
    if (right < size && arr[right].CPI > arr[largest].CPI) {
        largest = right;
    }
    if (largest != parent) {
        swap(&arr[parent], &arr[largest]);
        heapify(arr, largest, size);
    }
}

// Function to perform heap sort
void heapsort(Student* students, int n)
{
    int size = n;
    // Build max heap
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(students, i, size);
    }

    // Heap sort
    for (int i = size - 1; i >= 0; i--) {
        swap(&students[0], &students[i]);
        heapify(students, 0, i);
    }
}
