#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Define a structure for student information
typedef struct _Student {
    char* name;
    int roll_no;
    float CPI;
} Student;

// Function to heapify an array at index 'parent' of size 'size'
void heapify(Student* arr, int parent, int size) {
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    int largest = parent;

    // Check if left child exists and is greater than parent
    if (left < size && arr[left].CPI > arr[largest].CPI) {
        largest = left;
    }

    // Check if right child exists and is greater than largest so far
    if (right < size && arr[right].CPI > arr[largest].CPI) {
        largest = right;
    }

    // If the largest is not the parent, swap and recursively heapify the affected subtree
    if (largest != parent) {
        Student temp = arr[parent];
        arr[parent] = arr[largest];
        arr[largest] = temp;
        heapify(arr, largest, size);
    }
}

int main() {
    int n = 0;
    printf("Enter the number of students: ");
    scanf("%i", &n);

    // Allocate memory for an array of 'n' students
    Student* students = (Student*)malloc(sizeof(Student) * n);

    printf("Enter student details (Name RollNo CPI separated by space):\n");
    for (int i = 0; i < n; i++) {
        Student temp;
        char buffer[100];

        printf("Enter Student %i info: ", i + 1);
        scanf("%99s %d %f", buffer, &temp.roll_no, &temp.CPI);

        // Allocate memory for the student's name and copy the string
        temp.name = (char*)malloc(strlen(buffer) + 1);
        strcpy(temp.name, buffer);

        students[i] = temp;
    }

    printf("\nStudents' Information:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\tRoll No: %d\tCPI: %.2f\n", students[i].name, students[i].roll_no, students[i].CPI);
    }

    // Build a max heap
    int size = n;
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(students, i, size);
    }

    // Heap sort
    for (int i = size - 1; i >= 0; i--) {
        Student temp = students[0];
        students[0] = students[i];
        students[i] = temp;
        heapify(students, 0, i);
    }

    printf("\nStudents' Information (Sorted by CPI):\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\tRoll No: %d\tCPI: %.2f\n", students[i].name, students[i].roll_no, students[i].CPI);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(students[i].name);
    }
    free(students);

    return 0;
}
