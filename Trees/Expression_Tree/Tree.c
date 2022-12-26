#include "Tree.h"

Node * new(expression x){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->ex = x;
}

bool insert(Tree* t, expression x){
    if(!(*t)){
        *t = new(x);
        return true;
    }
    else if((*t)->ex.t == op){
        if(!(insert(&((*t)->left),x))){
            return insert(&((*t)->right),x);
        }
    }
    else{
        return false;
    }
}

int calculate(Tree t){
    if(t->ex.t == value) return t->ex.value;

    int left_value = calculate(t->left);
    int right_value = calculate(t->right);

    int result;
    switch(t->ex.op){
        case '+': result = (left_value + right_value); break;
        case '-': result = (left_value - right_value); break;
        case '*': result = (left_value * right_value); break;
        case '/': result = (left_value / right_value); break;
        case '%': result = (left_value % right_value); break;
    }
    return result;
}

expression insert_expression(int value, char oper, type x){
    expression y;
    if(x == op){
        y.op = oper;
        y.t = x;
    }
    else{
        y.value = value;
        y.t = x;
    }
    return y;
}

