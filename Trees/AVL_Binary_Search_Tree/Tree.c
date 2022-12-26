#include "Tree.h"

Node* new(int data){
    Node* new_node = (Node*) malloc(sizeof(Node));
    
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->height = 0;
    new_node->data = data;
    
    return new_node;
}

// Returns the largest value
int max(int x, int y){
    if (x>y) return x;
    else return y;
}

// Returns the height of a root if it exists and -1 if the root is null
int h(Tree root){
    if(!root) return -1;
    else return root->height;
}

// Calculates the balancing factor defined by the height of the left child subtracted by the height of the right child of the root
int balancing_factor(Tree root){
    if(root) return h(root->left) - h(root->right);
    return 0;
}

void left_rotation(Tree * root){
    Node * aux = (*root)->right->left;

    (*root)->right->left = *root;
    (*root) = (*root)->right;
    (*root)->left->right = aux;

    (*root)->left->height = max(h((*root)->left->left),h((*root)->left->right)) +1;
    (*root)->height = max(h((*root)->left), h((*root)->right)) +1;
}

void right_rotation(Tree * root){
    Node * aux = (*root)->left->right;

    (*root)->left->right = *root;
    (*root) = (*root)->left;
    (*root)->right->left = aux;

    (*root)->right->height = max(h((*root)->right->left),h((*root)->right->right)) +1;
    (*root)->height = max(h((*root)->left), h((*root)->right)) +1;
}

bool insert(Tree * root, int data){
    bool inserted;
    if(!(*root)){
        (*root) = new(data);
        return true;
    }
    if(data==(*root)->data) return false;
    else if(data < (*root)->data) inserted = insert(&((*root)->left),data);
    else if(data > (*root)->data) inserted = insert(&((*root)->right),data);

    if(inserted){
        (*root)->height = max(h((*root)->left), h((*root)->right)) +1;
        int bal_factor = balancing_factor(*root);
        
        switch(bal_factor){
            case(2):{
                if( balancing_factor((*root)->left) == -1){
                    left_rotation(&((*root)->left));
                }
                right_rotation(&(*root));
            } break;
            case(1): return true; break;
            case(0): return true; break;
            case(-1): return true; break;
            case(-2):{
                if(balancing_factor((*root)->right)== 1){
                    right_rotation(&((*root)->right));
                }
                left_rotation(&(*root));
            }break;

        }
        return true;
    }
    return false;
}

bool search(Tree t, int target){
    if(!t) return false;
    else if(t->data == target) return true;
    else if(t->data < target) return search(t->right, target);
    else if(t->data > target) return search(t->left, target);
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