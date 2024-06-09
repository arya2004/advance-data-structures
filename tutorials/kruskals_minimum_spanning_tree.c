#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 9999999
#define V 6

// Function to find the parent of a vertex in the union-find data structure
int find_parent(int vertex, int* parent) {
    while (parent[vertex] != vertex) {
        vertex = parent[vertex];
    }
    return vertex;
}

// Function to perform union of two sets in the union-find data structure
void union_of_two(int vertex1, int vertex2, int* parent) {
    int root1 = find_parent(vertex1, parent);
    int root2 = find_parent(vertex2, parent);
    parent[root1] = root2;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void Kruskals(int graph[V][V], int vertices, int starting) {
    int parent[vertices], a, b;
    int min_weight = INT_MAX;
    int cost = 0;
    int edges_count = 0;

    // Initialize parent array with each vertex as its own parent
    for (int p = 0; p < vertices; ++p) {
        parent[p] = p;
    }
    parent[starting] = starting;

    while (edges_count < vertices - 1) {
        min_weight = INT_MAX;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (find_parent(i, parent) != find_parent(j, parent) && graph[i][j] < min_weight) {
                    min_weight = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union_of_two(a, b, parent);
        printf("%i :  %i %i %i \n", edges_count, a, b, graph[a][b]);
        edges_count++;
        graph[a][b] = INT_MAX;
        graph[b][a] = INT_MAX;
        cost = cost + min_weight;
    }
    fprintf(stderr, "Total cost of minimum spanning tree: %i\n", cost);
}

int main() {
    int Matrix[V][V] = {
        {INT_MAX, 2, 3, INT_MAX, INT_MAX, INT_MAX},
        {2, INT_MAX, 4, 5, 6, INT_MAX},
        {3, 4, INT_MAX, INT_MAX, 7, INT_MAX},
        {INT_MAX, 5, INT_MAX, INT_MAX, 6, 4},
        {INT_MAX, 6, 7, 6, INT_MAX, 3},
        {INT_MAX, INT_MAX, INT_MAX, 4, 3, INT_MAX}
    };
    Kruskals(Matrix, V, 0);

    return 0;
}
