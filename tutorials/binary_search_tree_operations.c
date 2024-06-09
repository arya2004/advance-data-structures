#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in the binary search tree
typedef struct _Node {
    int data;
    struct _Node* left;
    struct _Node* right;
} Node;

// Create a new empty binary search tree
Node* BST_new() {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = -1;  // Initialize with a placeholder value
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Recursive inorder traversal of the binary search tree
void inorder(Node* n) {
    if (n != NULL) {
        inorder(n->left);
        printf("%i ", n->data);
        inorder(n->right);
    }
}

// Insert a new node with data '_data' into the binary search tree rooted at 'n'
Node* BST_insert(Node* n, int _data) {
    Node* traversal = n;
    if (n->data == -1) {  // Check if the tree is empty
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

int main() {
    Node* meowOS = BST_new();
    BST_insert(meowOS, 55);
    BST_insert(meowOS, 52);
    BST_insert(meowOS, 78);
    BST_insert(meowOS, 56);
    BST_insert(meowOS, 75);
    BST_insert(meowOS, 12);
    inorder(meowOS);
   
    return 0;
}
