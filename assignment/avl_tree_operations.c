#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int Max(int a, int b) {
    return (a > b) ? a : b;
}

Node* CreateNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int Height(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int GetBalanceFactor(Node* node) {
    if (node == NULL) return 0;
    return (Height(node->left) - Height(node->right));
}

Node* RotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + Max(Height(y->left), Height(y->right));
    x->height = 1 + Max(Height(x->left), Height(x->right));

    return x;
}

Node* RotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + Max(Height(x->left), Height(x->right));
    y->height = 1 + Max(Height(y->left), Height(y->right));

    return y;
}

Node* AVL_Insert(Node* root, int data) {
    if (root == NULL) return CreateNode(data);

    if (data < root->data) root->left = AVL_Insert(root->left, data);
    else if (data > root->data) root->right = AVL_Insert(root->right, data);
    else {
        fprintf(stdout, "Error: Data already exists.");
        return root;
    }

    root->height = 1 + Max(Height(root->left), Height(root->right));
    int balanceFactor = GetBalanceFactor(root);

    if (balanceFactor > 1 && data < root->left->data)
        return RotateRight(root);

    if (balanceFactor < -1 && data > root->right->data)
        return RotateLeft(root);

    if (balanceFactor > 1 && data > root->left->data) {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }

    if (balanceFactor < -1 && data < root->right->data) {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* AVL_Delete(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) root->left = AVL_Delete(root->left, data);
    else if (data > root->data) root->right = AVL_Delete(root->right, data);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = AVL_Delete(root->right, temp->data);
        }
    }

    if (root == NULL) return root;

    root->height = 1 + Max(Height(root->left), Height(root->right));
    int balanceFactor = GetBalanceFactor(root);

    if (balanceFactor > 1 && GetBalanceFactor(root->left) >= 0)
        return RotateRight(root);

    if (balanceFactor < -1 && GetBalanceFactor(root->right) <= 0)
        return RotateLeft(root);

    if (balanceFactor > 1 && GetBalanceFactor(root->left) < 0) {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }

    if (balanceFactor < -1 && GetBalanceFactor(root->right) > 0) {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }

    return root;
}

void InorderTraversal(Node* node) {
    if (node != NULL) {
        InorderTraversal(node->left);
        printf("%d ", node->data);
        InorderTraversal(node->right);
    }
}

int main() {
    Node* root = NULL;
    int choice = 0;
    int data = 0;

    while (choice != 5) {
        printf("\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = AVL_Insert(root, data);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = AVL_Delete(root, data);
                break;
            case 3:
                printf("Inorder Traversal: ");
                InorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                choice = 5; // Exit loop
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
