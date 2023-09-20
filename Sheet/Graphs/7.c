/*Write a Program to implement Dijkstra’s algorithm to find shortest
distance between two nodes of a user defined graph. Use Adjacency Matrix
to represent a graph.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#define INT_MAX 9999999
#define INF 9999
#define V 5 


int mean_heap(int* _visited, int * _weight, int n)
{   
    int index_of_min = 0;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(_visited[i] != 1 && _weight[i] < min)
        {
            min = _weight[i];
            index_of_min = i;
        }
    }
    return index_of_min;
    
}

void Dijkstra(int  matrix[5][5], int start, const int n)
{
    int visited[n];
    int distance[n];
    for (int i = 0; i < n; i++)
    {
       distance[i] = INT_MAX;
       visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    for (int i = 0; i < n; i++)
    {
        int position = mean_heap(visited, distance, n);
        visited[position] = 1;
        for (int j = 0; j < n; j++)
        {
            if(visited[i] == 0 && matrix[position][j] + distance[position] < distance[j]){
                distance[j] = matrix[position][j] + distance[position];
                
            }
        }
        
    }
    
    printf("vertex distance\n");
    for (int k = 0; k < n; k++)
    {
        printf("%i\t%i\n", k, distance[k]);
    }
    

    
}



int main()
{

    // printf("enter weight. if no connection, then enter -1\n");
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
    

    int _g[5][5] = {{INT_MAX,4,8,INT_MAX,INT_MAX},{4,INT_MAX,2,5,INT_MAX},{8,2,INT_MAX,5,9},{INT_MAX,5,5,0,4},{INT_MAX,INT_MAX, 9, 4,INT_MAX}};

    Dijkstra(_g,0,5);
    
   
    return 0;
}





/*  int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };
*/