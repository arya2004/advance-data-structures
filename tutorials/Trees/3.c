#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef struct _Node{
    int data;
    struct _Node* left;
    struct _Node* right;
}Node;

Node* Stack[100];
int base = 0;
int top = -1;

Node* Stack2[100];
int base2 = 0;
int top2 = -1;


Node* BST_new()
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = NULL;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(Node* n)
{
    if (n != NULL)
    {
        inorder(n->left);
        printf("%i ", n->data);
        inorder(n->right);
    }
    
}

void postorder(Node* n)
{
    if (n != NULL)
    {
        postorder(n->left);
        
        postorder(n->right);
        printf("%i ", n->data);
    }
    
}



Node* BST_insert(Node* n, int _data)
{
    Node* traversal = n;
    if(n->data == NULL)
    {
        n->data = _data;
        return n;
    }
    
    while (traversal != NULL)
    {
        if (_data < traversal->data)
        {
            if (traversal->left == NULL)
            {
                traversal->left = (Node*) malloc(sizeof(Node));
                traversal = traversal->left;
                traversal->data = _data;
                traversal->left = NULL;
                traversal->right = NULL;
                return n;
            }
            else{
                traversal = traversal->left;
            }
            
        }
        else if(_data > traversal->data)
        {
            if(traversal->right == NULL)
            {
                traversal->right = (Node*) malloc(sizeof(Node));
                traversal = traversal->right;
                traversal->data = _data;
                traversal->left = NULL;
                traversal->right = NULL;
                return n;
            }
            else{
                traversal = traversal->right;
            }
        }
        else{
            fprintf(stderr, "DATA ALREADY IN BST");
        }
        
    }
    return n;
    
}

void PReorderITer(Node* T)
{
    //Node* temp = T;
    top++;
    Stack[top] = T;
    
    //printf("f");
    while (top != -1)
    {
        Node* temp =  Stack[top];
        top--;
        printf("%i ", temp->data);
        if(temp->right != NULL){
             top++;
            Stack[top] = temp->right;
            
        }
        if(temp->left != NULL){
              top++;
            Stack[top] = temp->left;
           
        }
        
    }
    

}

void INOrderItr(Node* T)
{   
    //top++;
  //  Stack[top] = T;
    Node* temp = T;

    while (true)
    {
        if(temp != NULL)
        {
            top++;
            Stack[top] = temp; 
            temp = temp->left;
        }
        else{
            if(top == -1) break;
            temp = Stack[top];
            top--;
            printf("%i ", temp->data);
            temp = temp->right;
        }
        
    }
    
}

void POstorderItr(Node* T){
    Node* temp = T;
    top++;
    Stack[top] = T;
    while (top != -1)
    {
        //pop
       temp = Stack[top];
       top--;

        //push
       top2++;
       Stack2[top2] = temp;
       if(temp->left != NULL) {
            top++;
            Stack[top] = temp->left; 
       }
       if(temp->right != NULL) {
            top++;
            Stack[top] = temp->right; 
       }
    }
    while (top2 != -1)
    {
        temp = Stack2[top2];
        top2--;
        printf("%i ", temp->data);
    }
    
    
}



int main()
{
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
