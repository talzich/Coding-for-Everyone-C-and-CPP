#include <stdio.h>
#include <stdlib.h>

// For this Binary tree, we will be using an integer as the data type 
typedef int Data;

// Defining a node
typedef struct node{
    Data d;
    struct node  *left;
    struct node *right;
}Node;

// Defining a tree as a pointer to a node. A logical way to think about it is to
// think of entire tree as en extansion of its root. 
typedef Node* BTree;

// Standard in order traversal of a binary tree
void in_order(BTree root){
    if(root == NULL)
        return;
    else{
        in_order(root->left);
        printf("%d\n", root->d);
        in_order(root->right);
    }
}

// Creating a new node, not adding it to any tree yet, or even giving it data.
// Dr. pohl wrote the return value of this method as BTree, but I find it more logical 
// to explicitly point out that we are returning a pointer to a node. That's because the 
// specific node we just created doesn't necessarily belong to a tree
Node *new_node(void){
    return malloc(sizeof(Node));
}

// Creating and initializing a new node.
// Similar to new_node(), I find it more logical
// to explicitly point out that we are returning a pointer to a node.
Node *init_node(Data d, Node *left, Node *right){
    Node *t;
    t = new_node();
    t->d = d;
    t->left = left;
    t->right = right;
    return t;
}

// This method creates a new tree recursively, i.e, for each node we will
// create its left and right subtrees and connect by that node.  
BTree create_tree(Data a[], int i, int size){
    if (i>=size)
        return NULL;
    else
        return init_node(a[i], create_tree(a, i*2+1, size), create_tree(a, i*2+2, size));
    
}

int main(void){
    int d[] = {0,1,2,3,4,5,6};
    BTree bt;
    bt = create_tree(d, 0, 7);
    in_order(bt);
    return 0;
}


