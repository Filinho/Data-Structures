#include "Tree.h"

Node * new(int data){
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

bool insert(Tree * t, int data){
    if(!(*t)){
        (*t) = new(data);
        return true;
    }

    else if(data > (*t)->data) return insert(&((*t)->right),data);
    else if(data < (*t)->data) return insert(&((*t)->left),data);

    return false;
}

bool search(Tree t, int target){
    if(!t) return false;
    else if(t->data == target) return true;
    else if(t->data < target) return search(t->right, target);
    else if(t->data > target) return search(t->left, target);
}

int largest_subtree(Tree * t){
    if((*t)->right == NULL){
        return (*t)->data;
    }
    else{
        return largest_subtree(((*t)->right));
    }
}
bool remov(Tree *t, int target){
    if(!(*t)) return false;
    else if((*t)->data == target){
        // If the pointed node is a leaf, it is just removed
        if(!((*t)->left) && !((*t)->right)){
            free(*t);
            (*t) = NULL;
            return true;
        }
        // If the pointed node is a root with two children, the node is replaced by the largest value from the left subtree and the node that contained that value is removed.
        else if((*t)->left && (*t)->right){
            int largest_l_sub = largest_subtree(&((*t)->left));
            (*t)->data = largest_l_sub;
            remov(&((*t)->left), largest_l_sub);
            return true;
        }
        // If the pointed node is a root and has only left children, the node is replaced by the left child and then removed.
        else if((*t)->left){
            Node* removed= *t;
            (*t) = (*t)->left;
            free(removed);
            return true;
        }
        // If the pointed node is a root and has only right children, the node is replaced by the right child and then removed.
        else if((*t)->right){
            Node* removed= *t;
            (*t) = (*t)->right;
            free(removed);
            return true;
        }
    }
    else if((*t)->data < target) return remov(&((*t)->right), target);
    else if((*t)->data > target) return remov(&((*t)->left), target);
}

void print(Tree t){
    if(!t){
        printf(".");
        return;
    }
    printf("[%d:l=", t->data);
    print(t->left);
    printf(",r=");
    print(t->right);
    printf("]");
}
