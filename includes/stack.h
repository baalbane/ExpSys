
#ifndef STACK_H_
# define STACK_H_


# define   STACK_BUFF_SIZE    1


typedef struct           t_Stack_node {
    void                *buffer[STACK_BUFF_SIZE];
    int                  buffer_pt;
    struct t_Stack_node *next;
}                        Stack_node;


typedef struct           t_Stack {
    Stack_node          *first;
    Stack_node          *last;
}                        Stack;


ret_type stack_new(Stack**);
ret_type stack_delete(Stack*);
void    *stack_pop(Stack*);
ret_type stack_push(Stack*, void*);
bool     stack_is_empty(Stack*);
void    *stack_get_last(Stack*);
#endif