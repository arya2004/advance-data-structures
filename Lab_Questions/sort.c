#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _Student
{
    char* name;
    int roll_no;
    float CPI;
}Student;

void merge(Student* arr, int l, int m, int r)
{
     int i, j, k; 
    const int n1 = m - l + 1; 
    const int n2 = r - m; 
  
    // Create temp arrays 
    Student L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 
  
    // Initial index of second subarray 
    j = 0; 
  
    // Initial index of merged subarray 
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
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    
    

}

void mergesort(Student* arr, int l, int h)
{
    if(l < h)
    {
        int mid = (l + h) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}


void swap(Student* a, Student* b)
{
    Student tepm = *a;
    *a = *b;
    *b = tepm;
}

int partition(Student* arr, int l, int h)
{   
    float pivot = arr[l].CPI;
    int i = l;
    int j = h;
   
    while (i < j)
    {
        while (arr[i].CPI <= pivot && i < h){
            i++;
        }
        

        while (arr[j].CPI > pivot){
            j--;
        }
        if(i < j){
        
           printf(" %i ", j);
            Student t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
        
    }
  
     Student t = arr[l];
    arr[l] = arr[j];
    arr[j] = t;

    printf("e");

    return j;
}

void quicksort(Student* arr, int l, int h)
{
    if(l < h){
        int j = partition(arr, l, h);
        quicksort(arr, l, j-1);
        quicksort(arr, j + 1, h);
    }
}

void heapty(Student* arr, int parent, int size)
{

    int left = 2*parent;
    int right = (2* parent) + 1;
    int largest = parent;
    if(left < size && arr[parent].CPI < arr[left].CPI){
        largest = left;
    }
    if(right < size && arr[right].CPI > arr[largest].CPI){
        largest = right;
    }
    if(largest != parent){
        Student temp = arr[parent];
        arr[parent] = arr[largest];
        arr[largest] = temp;
        heapty(arr, largest, size);

    }

}



int heapsort(Student* students, int n) {


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
   

}


int main(){

      Student students[18] = {
        {"John", 101, 7.5},
        {"Alice", 102, 8.2},
        {"Bob", 103, 6.8},
        {"Emma", 104, 9.3},
        {"David", 105, 7.0},
        {"Sarah", 106, 8.9},
        {"Michel", 107, 6.5},
        {"Olivia", 108, 9.1},
        {"Sophia", 109, 8.7},
        {"Ethan", 110, 7.2},
        {"Ava", 111, 8.4},
        {"Liam", 112, 6.9},
        {"Mia", 113, 9.7},
        {"Noah", 114, 7.8},
        {"Cotte", 115, 9.0},
        {"James", 116, 6.6},
        {"Amelia", 117, 8.3},
        {"Daniel", 118, 7.3}
    };

    //mergesort(students, 0, 18);
    quicksort(students,0, 17);
    printf("\n\n");
      for (int i = 0; i < 18; i++)
    {
        printf("Name:\t%s\t\tRoll No:\t%d\tCPI:\t%.2f\n", students[i].name, students[i].roll_no, students[i].CPI);
    }

   
    return 0;
}