#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 9999999
#define V 5

// Function to find the vertex with minimum distance among the unvisited vertices
int min_heap(int* visited, int* distance, int n) {
    int min_index = 0;
    int min_distance = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (visited[i] != 1 && distance[i] < min_distance) {
            min_distance = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to perform Dijkstra's algorithm to find shortest distance
void Dijkstra(int matrix[V][V], int start, const int n) {
    int visited[n];
    int distance[n];

    // Initialize distance and visited arrays
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        int current = min_heap(visited, distance, n);
        visited[current] = 1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && matrix[current][j] != INT_MAX && 
                distance[current] + matrix[current][j] < distance[j]) {
                distance[j] = distance[current] + matrix[current][j];
            }
        }
    }

    printf("Vertex Distance\n");
    for (int k = 0; k < n; k++) {
        printf("%i\t%i\n", k, distance[k]);
    }
}

int main() {
    int graph[V][V] = {
        {INT_MAX, 4, 8, INT_MAX, INT_MAX},
        {4, INT_MAX, 2, 5, INT_MAX},
        {8, 2, INT_MAX, 5, 9},
        {INT_MAX, 5, 5, 0, 4},
        {INT_MAX, INT_MAX, 9, 4, INT_MAX}
    };

    Dijkstra(graph, 0, V);

    return 0;
}
