#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

// Queue structure for BFS
typedef struct _Queue {
    int data[MAX_SIZE];
    int front, rear;
    int maxCapacity;
    int currentCapacity;
} Queue;

void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
    q->maxCapacity = MAX_SIZE;
    q->currentCapacity = 0;
}

int isFull(Queue* q) {
    return (q->currentCapacity == q->maxCapacity);
}

int isEmpty(Queue* q) {
    return (q->currentCapacity == 0);
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->maxCapacity;
    }

    q->data[q->rear] = value;
    q->currentCapacity++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a special value to indicate an error
    }

    int value = q->data[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->maxCapacity;
    }

    q->currentCapacity--;
    return value;
}

// Stack structure for DFS
typedef struct _Stack{
    int* data;
    int size;
    int top;
} Stack;

Stack* Stack_new(int _size)
{
    Stack* _s = (Stack*) malloc(sizeof(Stack));
    _s->size = _size;
    _s->top = -1;
    _s->data = (int*) malloc(sizeof(int) * _size);
}

void Stack_push(Stack* s, int data)
{
    s->top++;
    s->data[s->top] = data; 
}

int Stack_pop(Stack* s)
{   
    int temp = s->data[s->top];
    s->top--;
    return temp;
}

// Perform BFS on a graph
int BFS()
{
    int vertices = 8; // Number of vertices in the graph
    int graph[8][8] =  {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
    };
    int visited[8] = {0};
    int starting_vertex = 3;
    Queue q;
    initializeQueue(&q);
    enqueue(&q, starting_vertex);
    visited[starting_vertex] = 1;
    while (!isEmpty(&q))
    {
        int temp = dequeue(&q);
        printf("%i ", temp);
        for (int j = 0; j < vertices; j++)
        {
            if(graph[temp][j] == 1 && visited[j] != 1)
            {
                enqueue(&q, j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
    return 0;
}

// Perform DFS on a graph
int DFS()
{
    int vertices = 8;
    int graph[8][8] =  {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
    };
    int visited[8] = {0};
    int starting_vertex = 3;
    Stack* s = Stack_new(100);
    Stack_push(s, starting_vertex);
    visited[starting_vertex] = 1;
    while (s->top > -1)
    {
        int popped = Stack_pop(s);
        printf("%i ", popped);
        for (int j = 0; j < vertices; j++)
        {
            if (graph[popped][j] == 1 && visited[j] != 1)
            {
                Stack_push(s, j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
    return 0;
}

int main(){
    BFS();
    DFS();
    return 0;
}
