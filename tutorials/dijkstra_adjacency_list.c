/*
    File Name: dijkstra_adjacency_list.c
    Description: Program to implement Dijkstra’s algorithm to find the shortest distance between two nodes in a user-defined graph. 
    This program uses an adjacency list to represent the graph.
*/

#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 9999999
#define NODE_MAX 100

// Node structure for adjacency list
typedef struct _Node {
    int weight;
    int node;
    struct _Node* next;
} Node;

// Graph structure to hold the adjacency list and size
typedef struct _Graph {
    Node* vertices[NODE_MAX];
    int size;
} Graph;

// Function to initialize the graph
Graph* Graph_init(int _size) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->size = _size;
    for (int i = 0; i < _size; i++) {
        g->vertices[i] = NULL;
    }
    return g;
}

// Function to add an edge to the graph
void Graph_add(Graph* _g, int _src, int _dest, int _weight) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->weight = _weight;
    n->node = _dest;
    n->next = _g->vertices[_src];
    _g->vertices[_src] = n;

    Node* m = (Node*)malloc(sizeof(Node));
    m->weight = _weight;
    m->node = _src;
    m->next = _g->vertices[_dest];
    _g->vertices[_dest] = m;
}

// Function to find the index of the minimum weight node in the heap
int mean_heap(int* _visited, int* _weight, int n) {
    int index_of_min = 0;
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (_visited[i] != 1 && _weight[i] < min) {
            min = _weight[i];
            index_of_min = i;
        }
    }
    return index_of_min;
}

// Function to perform Dijkstra's algorithm
void Dijkstra(Graph* _g, int start, const int n) {
    int visited[n];
    int distance[n];
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        int position = mean_heap(visited, distance, n);
        Node* traversal = _g->vertices[position];
        visited[position] = 1;
        while (traversal != NULL) {
            if (visited[i] == 0 && traversal->weight + distance[position] < distance[traversal->node]) {
                distance[traversal->node] = traversal->weight + distance[position];
            }
            traversal = traversal->next;
        }
    }

    printf("Vertex Distance\n");
    for (int k = 0; k < n; k++) {
        printf("%i %i\n", k, distance[k]);
    }
}

int main() {
    int temp = 0;
    printf("Enter the number of vertices: ");
    scanf("%i", &temp);
    Graph* f = Graph_init(temp);

    int l = 0;
    printf("Enter the number of edges: ");
    scanf("%i", &l);
    for (int i = 0; i < l; i++) {
        int s = 0, d = 0, w = 0;
        printf("Enter source, destination, and weight for edge %i: ", i + 1);
        scanf("%i %i %i", &s, &d, &w);
        Graph_add(f, s, d, w);
    }

    int start_v = 0;
    printf("Enter the start vertex: ");
    scanf("%i", &start_v);

    Dijkstra(f, start_v, temp);
    printf("\nDotnet Meow\n");

    return 0;
}
