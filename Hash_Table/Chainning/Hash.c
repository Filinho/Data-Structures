#include "Hash.h"

void inicializate_table(Table * t, int size){
    t->T = (table_element*) malloc(size*sizeof(table_element));

    for(int i = 0;i<size;i++){
        t->T[i].next = NULL;
        t->T[i].in_use = False;
    }

    t->size_of_table = size;
}

bool insert_table(Table *t, int data){
    int x =h(data,t->size_of_table);
    if(t->T[x].in_use == False){
        t->T[x].data = data;
        t->T[x].in_use = True;
    }
    else{
        table_element* aux = (table_element*) malloc(sizeof(table_element));
        aux->next = t->T[x].next;
        aux->data = data;
        aux->in_use = True;
        t->T[x].next = aux;
    }
    return True;
}

bool search(Table *t, int data){
    int x = h(data, t->size_of_table);
    printf("%d ", t->T[x].data);
    if(t->T[x].data == data) return True;
    else{
        table_element * current = t->T[x].next;
        while(current && current->data!=data){
            printf("%d ",current->data);
            current = current->next;
        }
        printf("%d ",current->data);
        if(current == NULL) return False;
        else if(current->data == data && current!= NULL) return True;
        else return False;
    }
}

bool remov(Table *t, int data){
    int x = h(data, t->size_of_table);
    if(t->T[x].data == data){
        if(t->T[x].next){
            table_element * removed = t->T[x].next;
            t->T[x].data = removed ->data;
            t->T[x].next = removed->next;
            free(removed);
            return True;
        }
        else{
            t->T[x].data = -1;
            t->T[x].in_use = False;
            return True;
        }  
    }
    else{
        table_element * current = t->T[x].next;
        while(current->next && current->next->data != data){
            current = current -> next;
        }
        if(!current -> next) return False;
        else if(current ->next->data = data){
            table_element * removed = current->next;
            current->next = removed->next;
            free(removed);
            return True;
        }
    } 
    
}
