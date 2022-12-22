#include <stdio.h>
#include <stdlib.h>
/*Chainning is a method that use a linked-list to deal with colissions,
whenever it happen, a chain of boxes are used to solve the problem*/
typedef enum {False, True} bool;

typedef struct aux_element{
    struct aux_element* next;
    int data;
    bool in_use;
}table_element;

typedef struct{
    table_element * T;
    int size_of_table;
} Table;

/**/
int h(int data, int size_of_table){
    return data % size_of_table;
}

/**/
void inicializate_table(Table * t, int size);

/**/
bool insert_table(Table *t, int data);

/**/
bool search(Table *t, int data);

/**/
bool remov(Table *t, int data);
