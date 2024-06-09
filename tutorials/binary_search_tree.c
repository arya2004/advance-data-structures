// File name: binary_search_tree.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for the Binary Search Tree (BST) node
typedef struct _Node {
    int data;
    struct _Node* left;
    struct _Node* right;
} Node;

// Global variables for iterative traversal using stacks
Node* Stack[100];
int base = 0;
int top = -1;

Node* Stack2[100];
int base2 = 0;
int top2 = -1;

// Function prototypes
Node* BST_new();
void inorder(Node* n);
void postorder(Node* n);
Node* BST_insert(Node* n, int _data);
void PReorderITer(Node* T);
void INOrderItr(Node* T);
void POstorderItr(Node* T);

// Create a new Binary Search Tree node
Node* BST_new() {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = NULL;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Recursive inorder traversal of BST
void inorder(Node* n) {
    if (n != NULL) {
        inorder(n->left);
        printf("%i ", n->data);
        inorder(n->right);
    }
}

// Recursive postorder traversal of BST
void postorder(Node* n) {
    if (n != NULL) {
        postorder(n->left);
        postorder(n->right);
        printf("%i ", n->data);
    }
}

// Insert a node into the Binary Search Tree
Node* BST_insert(Node* n, int _data) {
    Node* traversal = n;
    if (n->data == NULL) {
        n->data = _data;
        return n;
    }

    while (traversal != NULL) {
        if (_data < traversal->data) {
            if (traversal->left == NULL) {
                traversal->left = (Node*)malloc(sizeof(Node));
                traversal = traversal->left;
                traversal->data = _data;
                traversal->left = NULL;
                traversal->right = NULL;
                return n;
            }
            else {
                traversal = traversal->left;
            }
        }
        else if (_data > traversal->data) {
            if (traversal->right == NULL) {
                traversal->right = (Node*)malloc(sizeof(Node));
                traversal = traversal->right;
                traversal->data = _data;
                traversal->left = NULL;
                traversal->right = NULL;
                return n;
            }
            else {
                traversal = traversal->right;
            }
        }
        else {
            fprintf(stderr, "DATA ALREADY IN BST");
        }
    }
    return n;
}

// Iterative preorder traversal of BST
void PReorderITer(Node* T) {
    top++;
    Stack[top] = T;
    
    while (top != -1) {
        Node* temp = Stack[top];
        top--;
        printf("%i ", temp->data);
        if (temp->right != NULL) {
            top++;
            Stack[top] = temp->right;
        }
        if (temp->left != NULL) {
            top++;
            Stack[top] = temp->left;
        }
    }
}

// Iterative inorder traversal of BST
void INOrderItr(Node* T) {
    Node* temp = T;

    while (true) {
        if (temp != NULL) {
            top++;
            Stack[top] = temp;
            temp = temp->left;
        }
        else {
            if (top == -1) break;
            temp = Stack[top];
            top--;
            printf("%i ", temp->data);
            temp = temp->right;
        }
    }
}

// Iterative postorder traversal of BST
void POstorderItr(Node* T) {
    Node* temp = T;
    top++;
    Stack[top] = T;
    while (top != -1) {
        temp = Stack[top];
        top--;
        top2++;
        Stack2[top2] = temp;
        if (temp->left != NULL) {
            top++;
            Stack[top] = temp->left;
        }
        if (temp->right != NULL) {
            top++;
            Stack[top] = temp->right;
        }
    }
    while (top2 != -1) {
        temp = Stack2[top2];
        top2--;
        printf("%i ", temp->data);
    }
}

int main() {
    Node* meowOS = BST_new();
    BST_insert(meowOS, 55);
    BST_insert(meowOS, 52);
    BST_insert(meowOS, 8);
    BST_insert(meowOS, 56);
    BST_insert(meowOS, 75);
    BST_insert(meowOS, 12);
    postorder(meowOS);
    printf("\n");
    POstorderItr(meowOS);
   
    return 0;
}
