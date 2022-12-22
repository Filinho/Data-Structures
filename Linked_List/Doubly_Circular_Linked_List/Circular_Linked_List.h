#include <stdio.h>
#include <stdlib.h>

typedef struct no_aux{
    struct no_aux *right;
    struct no_aux *left;
    int data;
} Node;

typedef Node* List;

typedef enum {False, True} bool;

Node* new(int data);

void initialize_list(List* head_list);

bool insert_end(List l, int data);

bool insert_beginning(List l, int data);

bool remove_end(List l);

bool remove_beginning(List l);

void print(List l);

bool search(List l, int data);

void destroy(List l);