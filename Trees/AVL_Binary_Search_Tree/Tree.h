#include <stdlib.h>
#include <stdio.h>

typedef enum {false, true} bool;
// Tree Structure
typedef struct aux_node{
    struct aux_node * right;
    struct aux_node * left;
    int height;
    int data;

} Node;

typedef Node * Tree;

/*Allocates a node that has null children and struct expression like the one passed as a parameter*/
Node* new(int data);

// Returns the largest value
int max(int x, int y);

// Returns the height of a root if it exists and -1 if the root is null
int h(Tree root);

// Calculates the balancing factor defined by the height of the left child subtracted by the height of the right child of the root
int balancing_factor(Tree root);

// 
void left_rotation(Tree * root);

void right_rotation(Tree * root);

bool insert(Tree * root, int data);

/*Search target in Tree t*/
bool search(Tree t, int target);

/*Print Tree T in format [e= l=]*/
void print(Tree t);