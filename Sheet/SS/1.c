/*WAP to implement Bubble sort and Quick Sort on 1D array of Student
structure (contains student_name, student_roll_no, total_marks), with
key as student_roll_no. And count the number of swap performed.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef struct _Student{
    char* student_name;
    int student_roll_no;
    int total_marks;
}Student;

void Student_Swap(Student* a, Student*b)
{
    Student temp = {(*a).student_name, (*a).student_roll_no ,(*a).total_marks};
    (*a).student_name = (*b).student_name;
    (*a).student_roll_no = (*b).student_roll_no;
    (*a).total_marks = (*b).total_marks;

    (*b).student_name = temp.student_name;
    (*b).student_roll_no = temp.student_roll_no;
    (*b).total_marks = temp.total_marks;

}

void Bubble_Sort()
{   
      Student students[18] = {
        {"Ryan", 118, 80},
        {"Quinn", 117, 86},
        {"Patrick", 116, 84},
        {"Olivia", 115, 79},
        {"Noah", 114, 91},
        {"Mia", 113, 82},
        {"Liam", 112, 93},
        {"Katherine", 111, 89},
        {"Jack", 110, 85},
        {"Ivy", 109, 90},
        {"Helen", 108, 81},
        {"Grace", 107, 94},
        {"Frank", 106, 76},
        {"Eve", 105, 88},
        {"David", 104, 78},
        {"Charlie", 103, 92},
        {"Bob", 102, 87},
        {"Alice", 101, 95}
    };

    int size_of_arr = 18;
    int swaps = 0;
    for (int i = 0; i < size_of_arr; i++)
    {
        for (int k = 0; k < size_of_arr; k++)
        {
            if(students[i].student_roll_no < students[k].student_roll_no )
            {   
                printf("%i %i\n", students[i].student_roll_no, students[k].student_roll_no);
                Student_Swap(&students[i], &students[k]);
                
                swaps++;
            }
        }
        
    }
    
    printf("swaps: %i\n\n", swaps);
    for (int j = 0; j < size_of_arr; j++)
    {
       printf("%i\n", students[j].student_roll_no);
    }
    

}


int main()
{
    Bubble_Sort();
   
    return 0;
}
