#include "Simple_Linked_List.h"

// Allocates a node with data = x and next = NULL.
Node* new(int x){
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->next = NULL;
    new_node->data = x;   
    
    return new_node;
}
// Allocates a Head Node with data = -1 and next = NULL.
void initialize_list(List * head_list){
    *head_list = new(-1);
}

// Insert 'data' at the end of the list l
bool insert_end(List  l ,int data){
    List current = l->next;

    while(current->next){
        current = current->next;
    }

    current ->next = new(data);
 
    return True;
}

// Insert 'data' at the beginning of the list l
bool insert_beginning(List l, int data){
    List new_node = new(data);

    new_node->next = l->next;
    l->next = new_node;

    return True;
}

// remove the last node from list l
bool remove_end(List  l){
    if(!l->next){
        return False;
    }

    List current = l->next;

    while(current->next->next){
        current = current->next;
    }

    Node* removed = current ->next->next;
    current->next = NULL;
    free(removed);
    return True;
}

// remove the first node from list l
bool remove_beginning(List l){
    if(!l->next){
        return False;
    }

    Node* removed = l->next;

    l->next = removed->next;
    free(removed);

    return True;
}

// print the list l in format : 'l: [ x, y ]; '
void print_list(List l){
    Node* current = l->next;
    printf("l: [ ");
    while(current){
        if(!current->next){
            printf("%d", current -> data);
        }
        else{
            printf("%d,  ", current -> data);
        }
        current = current ->next;
    }
    printf(" ];\n");
}

// search for 'data ' in list l
bool search(List l, int data){
    Node* current = l-> next;

    while(current){
        if(current->data==data)return True;
        current = current-> next;
    }
}

// deallocate the list l
void destroy(List l){
    while(l->next){
        remove_beginning(l);
    }
    free(l);
}