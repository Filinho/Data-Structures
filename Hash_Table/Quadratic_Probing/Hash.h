#include <stdio.h>
#include <stdlib.h>
#define slack_factor 5

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

/*Hash Function used*/
int h(int data, int size_of_table, int try){
   int x = (data + 17*try + 19*try*try) % size_of_table;
   return x;
}

/*Search for data in the Table*/
int search(Table *t, int data);

/*Initialize t->T as a vector with n_max_element * slack_factor positions*/
bool initialie_table(Table *t,int n_max_element);

/*Free the table*/
void destroy(Table *t);

/*Insert data in the table*/
int insert(Table *t, int data);

/*Remove Data from the tabe*/
bool remov(Table *t, int data);
