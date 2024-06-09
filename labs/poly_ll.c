#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _Node{
    int coeff;
    int exponent;
    struct _Node* next;
}Node;


int main(){

         int vertices = 8; // Number of vertices in the graph
    int graph[8][8] =  {
        {0, 1, 1, 0, 0, 0, 0, 0}, // Vertex 0 is connected to vertex 1
        {1, 0, 0, 1, 0, 0, 0, 0}, // Vertex 1 is connected to vertices 0 and 2
        {1, 0, 0, 1, 0, 0, 0, 0}, // Vertex 2 is connected to vertices 1 and 3
        {0, 1, 1, 0, 1, 0, 0, 0}, // Vertex 3 is connected to vertices 2 and 4
        {0, 0, 0, 1, 0, 1, 1, 0}, // Vertex 4 is connected to vertices 3 and 5
        {0, 0, 0, 0, 1, 0, 0, 1}, // Vertex 5 is connected to vertices 4 and 6
        {0, 0, 0, 0, 1, 0, 0, 1}, // Vertex 6 is connected to vertices 5 and 7
        {0, 0, 0, 0, 0, 1, 1, 0}  // Vertex 7 is connected to vertex 6
    };
    return 0;
}