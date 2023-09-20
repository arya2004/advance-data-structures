//
// Created by ziegler on 8/29/23.
//
#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>


#define INT_MAX 9999999
#define INF 9999
#define V 6


int find_parent(int i, int* parent)
{
    while (parent[i] != i ){
       //parent[i] = parent[parent[i]];
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

    //  printf("enter weight. if no connection, then enter -1\n");
    // int mat[V][V];
    // for (int i = 0; i < V; i++)
    // {
    //     for (int j = 0; j < V; j++)
    //     {   
    //         int temp = -1;
    //          printf("enter weight of %i-%i\n", i, j);
    //         fflush(stdin);
    //         scanf("%i", &temp);
    //         fflush(stdin);
    //         if(temp == -1){
    //             mat[i][j] = INT_MAX;
    //         }
    //         else{
    //             mat[i][j] = temp;
    //         }
    //     }
        
    // }
    // int k = 0;
    //  printf("enter start vertex");
    //         fflush(stdin);
    //         scanf("%i", &k);
    //         fflush(stdin);
    



    int Matrix[6][6] = {{INT_MAX,2,3,INT_MAX,INT_MAX, INT_MAX},{2,INT_MAX,4 ,5,6, INT_MAX},{3,4,INT_MAX,INT_MAX,7, INT_MAX},{INT_MAX,5,INT_MAX,INT_MAX,6, 4},{INT_MAX,6,7,6,INT_MAX, 3}, {INT_MAX, INT_MAX, INT_MAX, 4, 3, INT_MAX}};
    Krushkals(Matrix, V, 0);


 
    return 0;
}
