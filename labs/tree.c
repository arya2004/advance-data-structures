#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _Node{
    int val;
    struct _Node* left;
    struct _Node* right;
}Node;

Node* Stack[100];
int Top = -1;
Node* Stack2[100];
int Top2 = -1;

Node* BST_insert(Node* head, int data)
{
    if(head == NULL){
        head = (Node*) malloc(sizeof(Node));
        head->left = NULL;
        head->right = NULL;
        head->val = data;
        return head;
    }
    else
    {
        Node* traverse = head;
        while (1)
        {
            if(data < traverse->val)
            {
                if(traverse->left == NULL){
                    traverse->left = (Node*) malloc(sizeof(Node));
                    traverse = traverse->left;
                    traverse->left = NULL;
                    traverse->right = NULL;
                    traverse->val = data;
                    return head;
                }
                else{
                    traverse = traverse->left;
                }
            }
            else{
                if(traverse->right == NULL){
                    traverse->right = (Node*) malloc(sizeof(Node));
                    traverse = traverse->right;
                    traverse->left = NULL;
                    traverse->right = NULL;
                    traverse->val = data;
                    return head;
                }
                else{
                    traverse = traverse->right;
                }
            }
        }
        
    }
    return head;
}


void inorder(Node* head)
{
    if(head != NULL)
    {
        inorder(head->left);
        printf("%i ", head->val);
        inorder(head->right);
    }
}

void  non_inorder(Node* head)
{   
    Node* traverse = head;
    while (1)
    {   
        if(traverse != NULL){
            Top++;
            Stack[Top] = traverse;
            traverse = traverse->left;
        }
        else{
            if(Top == -1)
                break;
            traverse = Stack[Top];
            Top--;
            printf("%i ", traverse->val);
            traverse = traverse->right;
        }
        
    }
    
}


void postorder(Node* head)
{
    if(head != NULL)
    {
        postorder(head->left);
     
        postorder(head->right);
           printf("%i ", head->val);
    }
}

void non_postorder(Node* head)
{
    Top++;
    Stack[Top] = head;

    while (Top > -1)
    {
       Node* temp = Stack[Top];
       Top--;

       Top2++;
       Stack2[Top2] = temp;
       if(temp->left != NULL){
        Top++;
        Stack[Top] = temp->left;
       }
       if(temp->right != NULL){
        Top++;
        Stack[Top] = temp->right;
       }

    }
    while (Top2 > -1)
    {
        printf("%i ", Top2[Stack2]->val);
        Top2--;
    }
    
}

void preorder(Node* head)
{
    if(head != NULL)
    {   
         printf("%i ", head->val);
        preorder(head->left);
     
        preorder(head->right);
          
    }
}

void non_preorder(Node* head)
{
   
    Top++;
    Stack[Top] = head;

    while (Top > -1)
    {
        Node* temp = Stack[Top];
        Top--;
        printf("%i ", temp->val);
        
        //rigt then left
        if(temp->right != NULL){
        Top++;
        Stack[Top] = temp->right;
        }
        if(temp->left != NULL){
        Top++;
        Stack[Top] = temp->left;
       }
       
    }
    

 
    
}



int main(){

    Node* root = (Node*) malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    root->val = 44;

    BST_insert(root, 23);
    BST_insert(root, 88);
    BST_insert(root, 65);
    BST_insert(root, 36);
    BST_insert(root, 10);
  
    preorder(root);

    printf("\n");
    non_preorder(root);

    printf("\ndotntw raawrr");
     
    return 0;
}