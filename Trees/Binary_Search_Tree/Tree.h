#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
// Structure of the Tree
typedef struct node_aux{
    // tree nodes
    struct node_aux * right;
    struct node_aux * left;
    // struct expression
    int data;
}Node;


typedef Node * Tree;
/*Allocates a node that has null children and struct expression like the one passed as a parameter*/
Node * new(int data);
/*Allocates a node in the tree*/
bool insert(Tree * t, int data);
/*Search target in Tree t*/
bool search(Tree t, int target);
/*Returns the largest value in the subtree*/
int largest_subtree(Tree * t);
/*Remove Tardget from Tree t*/
bool  remov(Tree *t, int target);
/*Print Tree T in format [e= l=]*/
void print(Tree t);