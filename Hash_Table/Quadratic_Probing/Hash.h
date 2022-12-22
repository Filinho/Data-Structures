#include <stdio.h>
#include <stdlib.h>
#define slack_factor 5
/*Chainning is a method that use a linked-list to deal with colissions,
whenever it happen, a chain of boxes are used to solve the problem*/
typedef enum {False, True} bool;

typedef struct {
  bool in_use;
  bool used;
  int data;  
}table_element;

typedef struct{
    table_element * T;
    int size_of_table;
} Table;

/**/
int h(int data, int size_of_table, int try){
   int x = (data + 17*try + 19*try*try) % size_of_table;
   return x;
}

/**/
int search(Table *t, int data);

/**/
bool initialie_table(Table *t,int n_max_element);

/**/
void destroy(Table *t);

/**/
int insert(Table *t, int data);

/**/
bool remov(Table *t, int data);