#include "Circular_Linked_List.h"

// Allocates a node with data, which points to itself.
Node* new(int data){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->right = new_node;
    new_node->left = new_node;
    new_node->data = data;
    return new_node;
}
// Allocates a Head Node with data = -1, which points to itself.
void initialize_list(List* head_list){
    *head_list = new(-1);
}
// Insert 'data' at the end of the list l
bool insert_end(List l, int data){
    if(!l) return False;

    Node * new_node = new(data);

    new_node ->right = l;
    new_node ->left = l->left;
    l->left->right = new_node;
    l->left = new_node;
    
    return True;
}
// Insert 'data' at the beginning of the list l
bool insert_beginning(List l, int data){
    if(!l) return False;

    Node * new_node = new(data);

    new_node->right = l->right;
    new_node->left = l;
    l->right->left = new_node;
    l->right = new_node;
    
    return True;
}
// remove the last node from list l
bool remove_end(List l){
    if(!l) return False;

    Node * removed = l->left;
    l->left = removed ->left;
    removed -> left ->right= l;

    free(removed);

    return True;

}
// remove the first node from list l
bool remove_beginning(List l){
    if(!l) return False;

    Node * removed = l->right;
    l->right = removed ->right;
    removed -> right ->left= l;

    free(removed);

    return True;

}
// print the list l in format : 'l: [ x, y ]; '
void print(List l){
    if(!l) return;
    Node* current = l->right;

    printf("l: [ ");
    while(current != l){
    if(current->right == l){
            printf("%d", current -> data);
        }
        else{
            printf("%d,  ", current -> data);
        }
        current = current ->right;
    }
    printf(" ];\n");
}
// search for 'data ' in list l
bool search(List l, int data){
    if(!l) return False;
    Node* current =l->right;

    while(current != l){
        if(current->data==data){
            return True;
        }
        current = current -> right;
    }

    return False;
}
// deallocate the list l
void destroy(List l){

    while(l->right != l){
        remove_beginning(l);
    }
    free(l);
}
