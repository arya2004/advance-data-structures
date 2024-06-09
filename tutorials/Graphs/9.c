//
// Created by ziegler on 8/29/23.
//
#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>


#define INT_MAX 9999999
#define NODE_MAX 100


typedef struct _Node{
    int weight;
    int node;
    struct _Node* next;
}Node;

typedef struct _Graph{
    Node* vertices[NODE_MAX];
    int size;
}Graph;


Graph* Graph_init(int _size){
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->size = _size;
    for (int i = 0; i < _size; i++)
    {
        g->vertices[i] = NULL;
    }
    return g;
    
}

void Graph_add(Graph* g,int _initial, int _final, int _weight)
{
    Node* t = (Node*) malloc(sizeof(Node));
    t->weight = _weight;
    t->node = _final;
    t->next = g->vertices[_initial];
    g->vertices[_initial] = t;

    Node* q = (Node*) malloc(sizeof(Node));
    q->weight = _weight;
    q->node = _initial;
    q->next = g->vertices[_final];
    g->vertices[_final] = q;

}


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

void Krushkals(Graph* g, int n, int starting)
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
            Node* temp = g->vertices[i];
            while (temp != NULL)
            {
                if(find_parent(i, parent) != find_parent(temp->node, parent) && temp->weight < min ){
                    min = temp->weight;
                    a = i;
                    b = temp->node ;
                }
                temp = temp->next;
            }
            



            // for (int j = 0; j < n; j++) {
            //     if(find_parent(i, parent) != find_parent(j, parent) && A[i][j] < min ){
            //         min = A[i][j];
            //         a = i;
            //         b = j ;
            //     }
            // }
        }


        union_of_two(a,b,parent);
        printf("%i :  %i %i  \n", number_of_edges, a,b);
        number_of_edges++;
        //A[a][b] = INT_MAX;
       // A[b][a] = INT_MAX;
        cost = cost + min;
    }
    fprintf(stderr, "cost: %i\n", cost);
}



int main() {
    int Matrix[6][6] = {{INT_MAX,   2,3,INT_MAX,INT_MAX, INT_MAX},
                        {2,     INT_MAX,    4 ,5,6, INT_MAX},
                        {3,4,       INT_MAX,    INT_MAX,7, INT_MAX},
                        {INT_MAX,5,INT_MAX, INT_MAX,     6, 4},
                        {INT_MAX,6,7,6,         INT_MAX,         3}, 
                        {INT_MAX, INT_MAX, INT_MAX, 4, 3,   INT_MAX}};
    // Graph* f = Graph_init(6);
    // Graph_add(f,0,1,2);
    // Graph_add(f,0,2,3);
    // Graph_add(f,1,2,4);
    // Graph_add(f,1,3,5);
    // Graph_add(f,1,4,6);
    // Graph_add(f,2,4,7);
    // Graph_add(f,3,4,6);
    //  Graph_add(f,3,5,4);
    // Graph_add(f,4,5,3);

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
 
   
   
    Krushkals(f, 6, start_v);
  // int* arr = (int*) malloc(sizeof(int) * 6);

 
    return 0;
}
