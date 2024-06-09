//
// Created by ziegler on 8/29/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_parent(int i, int* parent)
{
    while (parent[i] != i ){
      // parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

void union_of_two(int i, int j, int* parent)
{
    int x = find_parent(i, parent);
    int y = find_parent(j, parent);
    parent[x] = y;
}

void Krushkals(int A[6][6], int n, int starting)
{

    int parent[n], a,b;
    int min = INT_MAX;
    int cost = 0;
    int number_of_edges = 0;
    for (int p = 0; p < n; ++p) {
    parent[p] = p;
    }
    parent[starting] = starting;

    while (number_of_edges < n-1){
        min = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(find_parent(i, parent) != find_parent(j, parent) && A[i][j] < min ){
                    min = A[i][j];
                    a = i;
                    b = j ;
                }
            }
        }
        union_of_two(a,b,parent);
        printf("%i :  %i %i %i \n", number_of_edges, a,b,A[a][b]);
        number_of_edges++;
        A[a][b] = INT_MAX;
        A[b][a] = INT_MAX;
        cost = cost + min;
    }
    fprintf(stderr, "cost: %i\n", cost);
}



int main() {
    int Matrix[6][6] = {{INT_MAX,2,3,INT_MAX,INT_MAX, INT_MAX},{2,INT_MAX,4 ,5,6, INT_MAX},{3,4,INT_MAX,INT_MAX,7, INT_MAX},{INT_MAX,5,INT_MAX,INT_MAX,6, 4},{INT_MAX,6,7,6,INT_MAX, 3}, {INT_MAX, INT_MAX, INT_MAX, 4, 3, INT_MAX}};
<<<<<<< HEAD
    Krushkals(Matrix, 6, 0);
  // int* arr = (int*) malloc(sizeof(int) * 6);

 
=======
   Krushkals(Matrix, 6, 0);


    printf("dotnet meow\n");
>>>>>>> 85d68b78025099f9fc6fda6f4ff646030b0d2435
    return 0;
}
