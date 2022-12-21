
#include <stdio.h>
#include<stdlib.h>
// Node of the Matrix Structure
typedef struct no_aux{

    struct no_aux * right;
    struct no_aux * left;
    struct no_aux * up;
    struct no_aux * down;

    int data;
    int row;
    int column;

}Node;
// Matrix Structure
typedef struct{
    Node* head_node;
    int n_row;
    int n_column;
}Matrix;

typedef enum{False, True} bool;

// Allocates a node defining row, column and data.
Node* new(int row, int column, int data);

// sets the number of rows and columns in the matrix and allocates a head node that points to itself
void initialize_matrix(int n_row, int n_col, Matrix * m);

/*Searches the head node of the column indicated by the integer, if there is no new head node it is allocated*/
Node* column_head(Matrix *m, int n_column);

/*Searches the head node of the row indicated by the integer, if there is no new head node it is allocated*/
Node* row_head(Matrix* m, int n_row);

/* Inserts data into the matrix if it is different from 0*/
bool insert(Matrix m, int row, int column, int data);

/*Multiply matrix a by b and save to m*/
bool multiply(Matrix *m, Matrix a, Matrix b);

/*Sum matrix a by b and save to m*/
bool add(Matrix * m, Matrix a, Matrix b);

/*Subtract matrix a by b and save to m*/
bool sub(Matrix * m, Matrix a, Matrix b);


/*Deallocate the matrix nodes and set the number of rows and columns to 0*/
void zero(Matrix *m, int n_row, int n_column);

/*Deallocate the matrix nodes*/
void destroy(Matrix *m);

/*Prints the matrix in the format: (nlin=100,ncol=200,[0,3]=5,[0,8]=10,[2,9]=50,[5,3]=10,[5,15]=20,[99,0]=33);*/
void print(Matrix m);

