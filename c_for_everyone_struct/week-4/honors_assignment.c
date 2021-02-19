/*
    Honors assignment of week 4 of "C for everyone: Strucred Programming"
    by Tal Zichlinsky
*/

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
Node *new_node(void){
    return malloc(sizeof(Node));
}

// Creating and initializing a new node.
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

/*
	This method will take a file pointer, an int and an array and will read data from 
    the file into the array
*/
void read_file(FILE *ifp, int d[], int size){
	
    int i; 
    for(i = 0; i < size; i++){
        fscanf(ifp, "%d", &d[i]);
    }
}

int main(int argc, char *argv[]){
    
    FILE *ifp; // This file will be our input file
    int n; // Size of the array

    // Checking number of arguments
    if(argc != 2){
        printf("Wrong number of arguments, please specify only input file name\n");
        exit(1);
    }
    
    // Opening the file
    ifp = fopen(argv[1], "r");

    // If the file is valid, declare an array data of size n
    if(fscanf(ifp, "%d", &n) != 1){
        printf("File empty\n");
        exit(1);
    }
    int data[n];

    // It's importent not to rewind before that point
    read_file(ifp, data, n);

    BTree bt;
    bt = create_tree(data, 0, n);
    in_order(bt);
    fclose(ifp);
    return 0;
}


