/*
    File Name: sort_students.c
    Description: Program to implement Bubble sort and Quick Sort on a 1D array of Student structures. The key for sorting is the student_roll_no.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Student{
    char* student_name;
    int student_roll_no;
    int total_marks;
} Student;

// Function to swap two Student structures
void Student_Swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort on the array of students
void Bubble_Sort(Student* students, int size_of_arr, int* swaps) {
    *swaps = 0;
    for (int i = 0; i < size_of_arr; i++) {
        for (int k = 0; k < size_of_arr - i - 1; k++) {
            if (students[k].student_roll_no > students[k + 1].student_roll_no) {
                Student_Swap(&students[k], &students[k + 1]);
                (*swaps)++;
            }
        }
    }
}

// Function to partition the array for Quick Sort
int Quick_Partition(Student* students, int low, int high, int* swaps) {
    int pivot = students[high].student_roll_no;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (students[j].student_roll_no < pivot) {
            i++;
            Student_Swap(&students[i], &students[j]);
            (*swaps)++;
        }
    }
    Student_Swap(&students[i + 1], &students[high]);
    (*swaps)++;
    return (i + 1);
}

// Function to perform Quick Sort on the array of students
void Quick_Sort(Student* students, int low, int high, int* swaps) {
    if (low < high) {
        int pi = Quick_Partition(students, low, high, swaps);

        Quick_Sort(students, low, pi - 1, swaps);
        Quick_Sort(students, pi + 1, high, swaps);
    }
}

int main() {
    Student students[18] = {
        {"Ryan", 118, 80}, {"Quinn", 117, 86}, {"Patrick", 116, 84}, {"Olivia", 115, 79},
        {"Noah", 114, 91}, {"Mia", 113, 82}, {"Liam", 112, 93}, {"Katherine", 111, 89},
        {"Jack", 110, 85}, {"Ivy", 109, 90}, {"Helen", 108, 81}, {"Grace", 107, 94},
        {"Frank", 106, 76}, {"Eve", 105, 88}, {"David", 104, 78}, {"Charlie", 103, 92},
        {"Bob", 102, 87}, {"Alice", 101, 95}
    };

    int size_of_arr = sizeof(students) / sizeof(students[0]);
    int bubble_swaps = 0;
    Bubble_Sort(students, size_of_arr, &bubble_swaps);
    printf("Bubble Sort Swaps: %i\n", bubble_swaps);

    printf("\nSorted by Bubble Sort:\n");
    for (int j = 0; j < size_of_arr; j++) {
        printf("%i\n", students[j].student_roll_no);
    }

    int quick_swaps = 0;
    Quick_Sort(students, 0, size_of_arr - 1, &quick_swaps);
    printf("\nQuick Sort Swaps: %i\n", quick_swaps);

    printf("\nSorted by Quick Sort:\n");
    for (int j = 0; j < size_of_arr; j++) {
        printf("%i\n", students[j].student_roll_no);
    }

    return 0;
}
