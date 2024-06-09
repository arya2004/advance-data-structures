/*Write a Program to implement Dijkstra’s algorithm to find shortest
distance between two nodes of a user defined graph. Use Adjacency List
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
#define NODE_MAX 100


typedef struct _Node{
    int weight;
    int node;
    struct _Node* next;
}Node;

typedef struct _Graph{
    Node* vertice[NODE_MAX];
    int size;
}Graph;


Graph* Graph_init(int _size)
{
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->size = _size;
    for (int i = 0; i < _size; i++)
    {
        g->vertice[i] = NULL;
    }
    
    return g;
}

void Graph_add(Graph* _g, int _src, int _dest, int _weight)
{
    Node* n = (Node*) malloc(sizeof(Node));
    n->weight = _weight;
    n->node = _dest;
    n->next = _g->vertice[_src];
    _g->vertice[_src] = n;


    Node* m = (Node*) malloc(sizeof(Node));
    m->weight = _weight;
    m->node = _src;
    m->next = _g->vertice[_dest];
    _g->vertice[_dest] = m;
}


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




void Dijkstra(Graph* _g, int start, const int n)
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
        Node* traversal = _g->vertice[position];
        visited[position] = 1;
        while (traversal != NULL)
        {
             if(visited[i] == 0 && traversal->weight + distance[position] < distance[traversal->node]){
                distance[traversal->node] = traversal->weight + distance[position];
                
            }
            traversal = traversal->next;
        }
        
        // for (int j = 0; j < n; j++)
        // {
        //     if(visited[i] == 0 && matrix[position][j] + distance[position] < distance[j]){
        //         distance[j] = matrix[position][j] + distance[position];
                
        //     }
        // }
        
    }
    
         printf("vertex distance\n");
    for (int k = 0; k < n; k++)
    {
        printf("%i %i\n", k, distance[k]);
    }
    

    
}



int main()
{
    //int _g[5][5] = {{INT_MAX,4,8,INT_MAX,INT_MAX},{4,INT_MAX,2,5,INT_MAX},{8,2,INT_MAX,5,9},{INT_MAX,5,5,0,4},{INT_MAX,INT_MAX, 9, 4,INT_MAX}};

   // Dijkstra(_g,0,5);
   int temp = 0;
    printf("enter no of vertices\n");
            fflush(stdin);
            scanf("%i", &temp);
            fflush(stdin);
    Graph* f = Graph_init(temp);
     int l = 0;
    printf("enter no of edges\n");
            fflush(stdin);
            scanf("%i", &l);
            fflush(stdin);
            for (int i = 0; i < l; i++)
            {   
                int s = 0;
                int d = 0;
                int w = 0;
                printf("enter src dest and weight\n");
                fflush(stdin);
                scanf("%i %i %i", &s,&d,&w);
                fflush(stdin);
                Graph_add(f,s,d,w);
            }
        int start_v = 0;
     printf("enter start vertex\b");
            fflush(stdin);
            scanf("%i", &start_v);
            fflush(stdin);
            
    // Graph_add(f,0,1,7);
    // Graph_add(f,0,2,12);
    // Graph_add(f,1,2,2);
    // Graph_add(f,1,3,9);
    // Graph_add(f,2,4,10);
    // Graph_add(f,3,4,4);
    // Graph_add(f,4,5,5);
    // Graph_add(f,3,5,1);
     Dijkstra(f,start_v,);

    printf("\ndotnet meow");


   
    return 0;
}
