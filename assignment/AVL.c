#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


typedef struct _Node
{
    int data;
    struct _Node* left;
    struct _Node* right;
    int height;

}Node;

int Max(int a, int b)
{
    if (a > b)
        return a;
    return b;
        
}

Node* BST_new()
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = NULL;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int Height(Node* _n)
{
    if(_n == NULL)
    {
        return 0;
    }
    else
    {
        return _n->height;
    }
}

int GetBalanceFactor(Node* _n)
{
    if(_n == NULL)
    {
        return 0;
    }
    else
    {
        return (Height(_n->left) - Height(_n->right));
    }
}

Node* Rotate_Right(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + Max(Height(y->left),Height(y->right) );
    x->height = 1 + Max(Height(x->left), Height(x->right));

    return x;
}


Node* Rotate_Left(Node* y)
{
    Node* x = y->right;
    Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = 1 + Max(Height(y->left),Height(y->right) );
    x->height = 1 + Max(Height(x->left), Height(x->right));

    return x;
}

Node* AVL_Insert(Node* root, int _data)
{   

    //BST INSERT

    if(root->data == NULL)
    {
        root->data = _data;
        return root;
    }
  
    Node* traverse = root;
    while (traverse != NULL)
    {
       if(_data < traverse->data)
       {
            if(traverse->left == NULL)
            {
                traverse->left = (Node*) malloc(sizeof(Node));
                traverse = traverse->left;
                traverse->data = _data;
                traverse->left = NULL;
                traverse->right = NULL;
                return root;
            }
            else
            {
                traverse = traverse->left;
            }
        }
        else if(_data > traverse->data)
        {    
            if(traverse->right == NULL)
            {
                traverse->right = (Node*) malloc(sizeof(Node));
                traverse = traverse->right;
                traverse->data = _data;
                traverse->left = NULL;
                traverse->right = NULL;
                return root;
            }
            else{
                traverse = traverse->right;
            }
        }
        else
        {
        fprintf(stdout, "\nerror,data exists");
       
        return root;
        }
    }

     //AVL Part

    int balancefaactor;
    root->height = 1 + (Max(Height(root->left), Height(root->right)));
    balancefaactor = GetBalanceFactor(root);

    //LL
    if(balancefaactor > 1 && root->left->data > _data)
    {
        return Rotate_Right(root);
    }


    //RR

    if(balancefaactor < -1 && root->right->data  < _data)
    {
        return Rotate_Left(root);
    }

    //LR

    if(balancefaactor > 1 && root->right->data < _data)
    {
        root->left = Rotate_Left(root->left);
        return Rotate_Right(root);
    }

    //RL

    if(balancefaactor < -1 && root->right->data > _data)
    {
        root->right = Rotate_Right(root->right);
        return Rotate_Left(root);
    }
    
    return root;
}

Node * minValueNode(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 


Node* AVL_Delete(Node* root, int n)
{
    if(root == NULL)
        return root;
    
    if(n < root->data)
        root->left = AVL_Delete(root->left, n);
    else if(n > root->data)
        root->right = AVL_Delete(root->right, n);
    
    else
    {
        if(root->left == NULL || root->right == NULL)
        {
            Node* temp;
            if(root->left == NULL)
            {
                temp = root->right;
            }else{
                temp = root->left;
            }
            
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }else{
                *root = *temp;
            }
            free(temp);
         
        }
        else
        {
            Node* temp = minValueNode(root->right);
 
            root->data = temp->data;
 
            root->right = AVL_Delete(root->right, temp->data);
        }
    }

   
      //AVL Part
    if(root == NULL)
        return root;


    int balancefaactor;
    root->height = 1 + (Max(Height(root->left), Height(root->right)));
    balancefaactor = GetBalanceFactor(root);

    //LL
    if(balancefaactor > 1 && GetBalanceFactor(root->left) >= 0)
    {
        return Rotate_Right(root);
    }


    //RR

    if(balancefaactor < -1 && GetBalanceFactor(root->right) <= 0)
    {
        return Rotate_Left(root);
    }

    //LR

    if(balancefaactor > 1 && GetBalanceFactor(root->left) < 0)
    {
        root->left = Rotate_Left(root->left);
        return Rotate_Right(root);
    }

    //RL

    if(balancefaactor < -1 && GetBalanceFactor(root->right) > 0)
    {
        root->right = Rotate_Right(root->right);
        return Rotate_Left(root);
    }
    
    return root;

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





int main() {

  Node* kek = BST_new();
//   kek =  AVL_Insert(kek, 33);
//   kek =  AVL_Insert(kek, 67);
//   kek =  AVL_Insert(kek, 88);
//    kek = AVL_Insert(kek, 40);
//    kek =  AVL_Insert(kek, 10);
//    inorder(kek);
//    kek =  AVL_Delete(kek, 33);
//  inorder(kek);

   
//    printf("\ndotnew");
  
//     inorder(kek);
  
    int val = 0;
    int  pp = 0;
    while (val == 0)
    {
        printf("\n0> Quit 1> Create 2> Insert 3>  Delete 4> Inorder Print: ");
        scanf("%i", &pp);
        if(pp == 0)
        {
            val = 1;
        }
        else if(pp == 1)
        {
            kek = BST_new();
        }
        else if(pp == 2)
        {   
            int t = 0;
            printf("Enter val to add: ");
            scanf("%i", &t);
            AVL_Insert(kek, t);
        }
        else if(pp == 3)
        {
            int r = 0;
            printf("Enter val to delete: ");

            scanf("%i", &r);
            AVL_Delete(kek, r);
        }
        else if(pp == 4)
        {
            inorder(kek);
        }

    }
    
  
    
    return 0;
}
