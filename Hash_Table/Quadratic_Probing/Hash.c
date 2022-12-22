#include "Hash.h"

bool initialie_table(Table *t,int n_max_element){
  t->size_of_table = slack_factor*n_max_element;
  t->T = (table_element*) malloc(slack_factor*t->size_of_table*sizeof(table_element));

  for(int i = 0;i<t->size_of_table;i++){
    t->T[i].in_use = False;
    t->T[i].used = False;
  }

  return True;
}

void destroy(Table *t){
  free(t->T);
}

int insert(Table *t, int data){

  for(int try = 0; try <t->size_of_table;try++){
    int x = h(data,t->size_of_table,try);
    if(t->T[x].in_use == False){
      t->T[x].in_use = True;
      t->T[x].data = data;
      t->T[x].used = True;
      return x;
    }
  }
  return -1;
}

bool remov(Table *t, int data){
  int x = search(t, data);
  if(x == -1) return False;
  else{
    t->T[x].in_use = False;
    t->T[x].data = -1;
    t->T[x].used = True;
  } 
  return True;
}

int search(Table *t, int data){
    for(int try = 0; try <t->size_of_table;try++){
    int x = h(data,t->size_of_table,try);
    if(t->T[x].used == False) return -1;
    else if(t->T[x].data == data && t->T[x].in_use == True) return x;
    }
    return -1;
}

