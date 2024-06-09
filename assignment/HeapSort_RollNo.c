#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef struct _Student
{
    char* name;
    int roll_no;
    float CPI;
}Student;

void heapty(Student* arr, int parent, int size)
{

    int left = 2*parent;
    int right = (2* parent) + 1;
    int largest = parent;
    if(left < size && arr[parent].roll_no < arr[left].roll_no){
        largest = left;
    }
    if(right < size && arr[right].roll_no > arr[largest].roll_no){
        largest = right;
    }
    if(largest != parent){
        Student temp = arr[parent];
        arr[parent] = arr[largest];
        arr[largest] = temp;
        heapty(arr, largest, size);

    }

}


int main() {

    int n = 0;
    printf("Enter no of students: ");
    scanf("%i", &n);

    Student* students = (Student*) malloc(sizeof(Student) * n);
    //   Student students[18] = {
    //     {"John", 101, 7.5},
    //     {"Alice", 102, 8.2},
    //     {"Bob", 103, 6.8},
    //     {"Emma", 104, 9.3},
    //     {"David", 105, 7.0},
    //     {"Sarah", 106, 8.9},
    //     {"Michel", 107, 6.5},
    //     {"Olivia", 108, 9.1},
    //     {"Sophia", 109, 8.7},
    //     {"Ethan", 110, 7.2},
    //     {"Ava", 111, 8.4},
    //     {"Liam", 112, 6.9},
    //     {"Mia", 113, 9.7},
    //     {"Noah", 114, 7.8},
    //     {"Cotte", 115, 9.0},
    //     {"James", 116, 6.6},
    //     {"Amelia", 117, 8.3},
    //     {"Daniel", 118, 7.3}
    // };

    
    printf("Name Rollno CPI separated by space\n");
    for (int i = 0; i < n; i++)
    {       
       Student temp;
        char buffer[100];

        printf("\nEnter Student %i info: ", i);


        scanf("%99s %d %f", buffer, &temp.roll_no, &temp.CPI);


        temp.name = (char*)malloc(strlen(buffer) + 1);
        strcpy(temp.name, buffer);

        students[i] = temp;
        
    }

      for (int i = 0; i < n; i++)
    {
        printf("Name:\t%s\t\tRoll No:\t%d\tCPI:\t%.2f\n", students[i].name, students[i].roll_no, students[i].CPI);
    }
    int size = n;
    for (int i = (size/2) - 1; i >= 0; i--)
    {
        heapty(students, i, size);
    }
    for (int i = size -1; i >= 0; i--)
    {
        Student temp = students[0];
        students[0] = students[i];
        students[i] = temp;
        heapty(students, 0, i);
    }
    printf("\n\n");
      for (int i = 0; i < n; i++)
    {
        printf("Name:\t%s\t\tRoll No:\t%d\tCPI:\t%.2f\n", students[i].name, students[i].roll_no, students[i].CPI);
    }

}
