#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 9999999
#define NODE_MAX 100

typedef struct _Node {
    int weight;
    int node;
    struct _Node* next;
} Node;

typedef struct _Graph {
    Node* vertices[NODE_MAX];
    int size;
} Graph;

// Function to initialize a graph with a given size
Graph* Graph_init(int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = size;
    for (int i = 0; i < size; i++)
        graph->vertices[i] = NULL;
    return graph;
}

// Function to add an edge to the graph
void Graph_add(Graph* graph, int initial, int final, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->weight = weight;
    newNode->node = final;
    newNode->next = graph->vertices[initial];
    graph->vertices[initial] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->weight = weight;
    newNode->node = initial;
    newNode->next = graph->vertices[final];
    graph->vertices[final] = newNode;
}

// Function to find the parent node in a disjoint set
int find_parent(int i, int* parent) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to perform union of two nodes in a disjoint set
void union_of_two(int i, int j, int* parent) {
    int x = find_parent(i, parent);
    int y = find_parent(j, parent);
    parent[x] = y;
}

// Function to implement Kruskal's algorithm
void Kruskal(Graph* graph, int numVertices, int startingVertex) {
    int parent[numVertices];
    int a, b;
    int min, cost = 0;
    int numberOfEdges = 0;

    for (int p = 0; p < numVertices; ++p)
        parent[p] = p;
    parent[startingVertex] = startingVertex;

    while (numberOfEdges < numVertices - 1) {
        min = INT_MAX;
        for (int i = 0; i < numVertices; i++) {
            Node* temp = graph->vertices[i];
            while (temp != NULL) {
                if (find_parent(i, parent) != find_parent(temp->node, parent) && temp->weight < min) {
                    min = temp->weight;
                    a = i;
                    b = temp->node;
                }
                temp = temp->next;
            }
        }

        union_of_two(a, b, parent);
        printf("%i :  %i %i  \n", numberOfEdges, a, b);
        numberOfEdges++;
        cost += min;
    }
    fprintf(stderr, "cost: %i\n", cost);
}

int main() {
    int numVertices;
    printf("Enter number of vertices: ");
    scanf("%i", &numVertices);
    getchar();

    Graph* graph = Graph_init(numVertices);

    int numEdges;
    printf("Enter number of edges: ");
    scanf("%i", &numEdges);
    getchar();

    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        printf("Enter source, destination, and weight of edge %i: ", i + 1);
        scanf("%i %i %i", &src, &dest, &weight);
        getchar();
        Graph_add(graph, src, dest, weight);
    }

    int startVertex;
    printf("Enter start vertex: ");
    scanf("%i", &startVertex);
    getchar();

    Kruskal(graph, numVertices, startVertex);

    // Free memory for graph nodes
    for (int i = 0; i < numVertices; i++) {
        Node* temp = graph->vertices[i];
        while (temp != NULL) {
            Node* prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(graph);

    return 0;
}
