#include <stdio.h>
#include <stdlib.h>

// Simple linked list structure 
typedef struct aux_node{
    struct aux_node *next;
    int data;
}Node;

typedef Node * List;

typedef enum {False, True} bool;

Node* new(int x);

void initialize_list(List * head_list);

bool insert_end(List  l ,int data);

bool insert_beginning(List l, int data);

bool remove_end(List l);

bool remove_beginning(List l);

void print_list(List l);

bool search(List l, int data);

void destroy(List l);