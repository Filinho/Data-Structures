#include <stdio.h>
#include <stdlib.h>

typedef enum {op,value} type;

typedef enum {false, true} bool;
// struct expression
typedef struct{
    type t;
    int value;
    char op;
}expression;
// Structure of the Tree
typedef struct node_aux{
    // tree nodes
    struct node_aux * right;
    struct node_aux * left;
    // struct expression
    expression ex;
}Node;


typedef Node * Tree;

/*Allocates a node that has null children and struct expression like the one passed as a parameter*/
Node * new(expression x);

/*Inserts an operand/value into the tree*/
bool insert(Tree* t, expression x);

/*Calculates the operation stored in the tree*/
int calculate(Tree t);
/*Generates an operand of the expression from the passed parameter*/
expression insert_expression(int value, char oper, type x);