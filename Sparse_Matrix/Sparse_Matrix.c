# include "Sparse_Matrix.h"

Node* new(int row, int column, int data){
    Node* new_node= (Node*) malloc(sizeof(Node));

    new_node->left = new_node;
    new_node->right = new_node;
    new_node->down = new_node;
    new_node->up = new_node;
    
    new_node->data = data;
    new_node->row = row;
    new_node->column = column;

    return new_node;
}

void initialize_matrix(int n_row, int n_col, Matrix * m){
    m->head_node = new(-1,-1,-1);

    m->n_column = n_col;
    m->n_row = n_row;
}

Node* column_head(Matrix *m, int n_column){
    Node* current_column = m->head_node->right;

    while(current_column != m->head_node && current_column->column < n_column) current_column = current_column -> right;

    if(current_column->column == n_column && current_column != m->head_node) return current_column;

    Node* new_node = new(-1, n_column, -1);

    new_node->right = current_column;
    new_node->left = current_column->left;

    current_column->left->right = new_node;
    current_column->left = new_node;

    return new_node;
}

Node* row_head(Matrix* m, int n_row){
    Node* current_row = m->head_node->down;

    while(current_row != m->head_node && current_row->row < n_row) current_row = current_row -> down;

    if(current_row->row == n_row && current_row != m->head_node) return current_row;

    Node* new_node = new(n_row,-1, -1);

    new_node->down = current_row;
    new_node->up = current_row->up;

    current_row->up->down = new_node;
    current_row->up = new_node;

    return new_node;
}

bool insert(Matrix m, int row, int column, int data){
    if(row>m.n_row || column>m.n_column) return False;
    if(data == 0) return True;
    Node * c_head = column_head(&m, column);
    Node * r_head = row_head(&m, row);

    Node * current_r = r_head -> right;
    Node * current_c = c_head -> down;

    while(current_r != r_head && current_r->column < column) current_r = current_r ->right;

    if(current_r->column == column && current_r != r_head){
        current_r -> data = data;
        return True;
    }

    while(current_c != c_head && current_c->row < row) current_c = current_c->down;

    Node* new_node = new(row,column,data);

    new_node ->right = current_r;
    new_node ->left = current_r -> left;
    current_r -> left -> right = new_node;
    current_r -> left = new_node;

    new_node->down = current_c;
    new_node->up = current_c -> up;
    current_c -> up -> down = new_node;
    current_c -> up = new_node;

    return True; 
}

bool multiply(Matrix *m, Matrix a, Matrix b){
    if(a.n_column != b.n_row) return False;
    zero(m,a.n_row,b.n_column);
    initialize_matrix(a.n_row, b.n_column, m);
    
    Node* r_head = a.head_node->down;
    Node* c_head = b.head_node->right;
    int value = 0;
    Node* current_r = r_head->right;
    Node* current_c = c_head->down;

    while(r_head != a.head_node){
        current_r = r_head ->right;
        Node* c_head = b.head_node->right;

        while(c_head != b.head_node){
            current_r = r_head ->right;
            current_c = c_head -> down;

            while(current_c != c_head && current_r != r_head){
                
                if(current_c->row == current_r->column){
                    value = (current_c->data * current_r->data) + value;
                    current_c = current_c -> down;
                    current_r = current_r -> right;
                }
                else if (current_c->row < current_r-> column) current_c = current_c -> down;
                else current_r = current_r -> right;
            }
        
        insert(*m,r_head->row, c_head->column,value);
        value = 0;
        c_head = c_head -> right;

        }
    r_head = r_head -> down;
    }
}

bool add(Matrix * m, Matrix a, Matrix b){
    if(a.n_row!= b.n_row || a.n_column != b.n_column) return False;
    initialize_matrix(a.n_row, b.n_column,m);

    Node* a_head = a.head_node->down;
    Node* b_head = b.head_node->down;

    while( a_head != a.head_node && b_head != b.head_node){

        Node* current_a = a_head->right;
        Node* current_b = b_head->right;
        if(current_a ->row == current_b->row){
            while(current_a != a_head && current_b != b_head){

                if(current_a -> column == current_b -> column){

                    int value = current_a->data + current_b->data;
                    insert(*m,current_a->row,current_a->column,value);
                
                    current_a = current_a ->right;
                    current_b = current_b -> right;
                }
                else if(current_a->column > current_b->column){
                    insert(*m, current_b->row, current_b->column,current_b->data);
                    current_b = current_b ->right;

                }
                else{
                    insert(*m, current_a->row, current_a->column,current_a->data);
                    current_a = current_a ->right;
                }
            }
        
            if(current_a != a_head){

                insert(*m,current_a->row,current_a->column,current_a->data );
                current_a = current_a ->right;

            }
            else if (current_b != b_head){

                insert(*m,current_b->row,current_b->column,current_b->data );
                current_b = current_b ->right;

            }

            a_head = a_head ->down;
            b_head = b_head ->down;
        }
        else if(current_a->row > current_b->row){
            while(current_b != b_head){

                insert(*m, current_b->row, current_b->column,current_b->data);
                current_b = current_b ->right;

            }

            b_head = b_head ->down;
        }
        else {

            while(current_a != a_head){
                insert(*m, current_a->row, current_a->column,current_a->data);
                current_a = current_a ->right;
            }

            a_head = a_head ->down;
        }
    }
    if(a_head == a.head_node && b_head == b.head_node ) return True;
    else if(a_head == a.head_node){
        while(b_head != b.head_node){
            Node* current_b  = b_head ->right;
            while(current_b != b_head){

                insert(*m, current_b->row, current_b->column,current_b->data);
                current_b = current_b ->right;

            }
            b_head = b_head ->down;
        }
    }
    else{
        while(b_head != b.head_node){
            Node* current_a  = a_head ->right;
            while(current_a != a_head){

                insert(*m, current_a->row, current_a->column,current_a->data);
                current_a = current_a->right;

            }
            a_head = a_head ->down;
        }
    }
    return True;
}

bool sub(Matrix * m, Matrix a, Matrix b){
    if(a.n_row!= b.n_row || a.n_column != b.n_column) return False;
    initialize_matrix(a.n_row, b.n_column,m);

    Node* a_head = a.head_node->down;
    Node* b_head = b.head_node->down;

    while( a_head != a.head_node && b_head != b.head_node){

        Node* current_a = a_head->right;
        Node* current_b = b_head->right;
        if(current_a ->row == current_b->row){
            while(current_a != a_head && current_b != b_head){

                if(current_a -> column == current_b -> column){

                    int value = current_a->data - current_b->data;
                    insert(*m,current_a->row,current_a->column,value);
                
                    current_a = current_a ->right;
                    current_b = current_b -> right;
                }
                else if(current_a->column > current_b->column){
                    insert(*m, current_b->row, current_b->column,-(current_b->data));
                    current_b = current_b ->right;

                }
                else{
                    insert(*m, current_a->row, current_a->column,current_a->data);
                    current_a = current_a ->right;
                }
            }
        
            if(current_a != a_head){

                insert(*m,current_a->row,current_a->column,current_a->data );
                current_a = current_a ->right;

            }
            else if (current_b != b_head){

                insert(*m,current_b->row,current_b->column,-(current_b->data) );
                current_b = current_b ->right;

            }

            a_head = a_head ->down;
            b_head = b_head ->down;
        }
        else if(current_a->row > current_b->row){
            while(current_b != b_head){

                insert(*m, current_b->row, current_b->column,-(current_b->data));
                current_b = current_b ->right;

            }

            b_head = b_head ->down;
        }
        else {

            while(current_a != a_head){
                insert(*m, current_a->row, current_a->column,current_a->data);
                current_a = current_a ->right;
            }

            a_head = a_head ->down;
        }
    }
    if(a_head == a.head_node && b_head == b.head_node ) return True;
    else if(a_head == a.head_node){
        while(b_head != b.head_node){
            Node* current_b  = b_head ->right;
            while(current_b != b_head){

                insert(*m, current_b->row, current_b->column,-(current_b->data));
                current_b = current_b ->right;

            }
            b_head = b_head ->down;
        }
    }
    else{
        while(b_head != b.head_node){
            Node* current_a  = a_head ->right;
            while(current_a != a_head){

                insert(*m, current_a->row, current_a->column,current_a->data);
                current_a = current_a->right;

            }
            a_head = a_head ->down;
        }
    }
    return True;
}

void destroy(Matrix *m){
    if(!m->head_node) return;
    Node* current = m->head_node->down;

    while(current!=m->head_node){

        Node* current_r = current->left;
        while(current_r != current){

            Node* removed = current_r;
            current_r = current_r -> left;
            free(removed);
        }
        Node * removed_head = current;
        current = current -> down;
        free(removed_head);

    }

    current = m->head_node->left;

    while(current!=m->head_node){

        Node* removed_head = current;
        current = current ->left;
        free(removed_head);
    }
    free(m->head_node);

}

void zero(Matrix *m, int n_row, int n_column){
    destroy(m);
    initialize_matrix(n_row,n_column,m);
}

void print(Matrix m){
    Node* current_head = m.head_node->down;
    printf("(n_rows = %d, n_columns = %d", m.n_row,m.n_column);
    while(current_head != m.head_node){
        Node* current = current_head->right;
        while(current != current_head){
            printf(" ,[%d,%d]=%d",current->row,current->column,current->data);
            current = current -> right;
        }
        current_head = current_head ->down;
    }
    printf(");\n");
}
