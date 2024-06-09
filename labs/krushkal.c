#include <stdio.h>
#include <limits.h>

#define V 4

// Function to find the parent of a node using path compression
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two sets
void unionSets(int parent[], int x, int y) {
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);
    parent[xRoot] = yRoot;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(int graph[][V]) {
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edgeCount = 0;
    while (edgeCount < V - 1) {
        int minWeight = INT_MAX, minSrc = -1, minDest = -1;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][j] != 0 && find(parent, i) != find(parent, j) && graph[i][j] < minWeight) {
                    minWeight = graph[i][j];
                    minSrc = i;
                    minDest = j;
                }
            }
        }

        if (minSrc != -1 && minDest != -1) {
            printf("Edge %d - %d: %d\n", minSrc, minDest, minWeight);
            unionSets(parent, minSrc, minDest);
            edgeCount++;
        }
    }
}

int main() {
    int graph[V][V] = {
            {0, 10, 6, 5},
            {10, 0, 0, 15},
            {6, 0, 0, 4},
            {5, 15, 4, 0}
    };

    kruskalMST(graph);

    return 0;
}
