
#include "main.h"



static ret_type stack_new_node(Stack_node **node_ptr) {
    Stack_node *new;

     if ((new = malloc(sizeof(Stack_node))) == NULL) {
        printf("MALLOC ERROR\n");
        return (CRITICAL_ERROR);
    }
    new->buffer_pt = 0;
    new->next = NULL;
    *node_ptr = new;
    return (OK);
}



ret_type stack_new(Stack **stack_ptr) {
    Stack *new;

    if ((new = malloc(sizeof(Stack))) == NULL) {
        printf("MALLOC ERROR\n");
        return (CRITICAL_ERROR);
    }
    if (stack_new_node(&(new->first)) != OK) {
        return (CRITICAL_ERROR);
    }
    new->last = new->first;
    *stack_ptr = new;
    return (OK);
}

static ret_type stack_delete_node(Stack_node *to_del) {
    if (to_del->next) {
        stack_delete_node(to_del->next);
    }
    free(to_del);
    return (OK);
}

ret_type stack_delete(Stack *to_del) {
    stack_delete_node(to_del->first);
    free(to_del);
    return (OK);
}

static ret_type stack_delete_last_node(Stack *stack) {
    Stack_node *tmp;

    tmp = stack->first;
    while (tmp->next != stack->last) {
        tmp = tmp->next;
    }
    free(stack->last);
    tmp->next = NULL;
    stack->last = tmp;
    return (OK);
}

void *stack_pop(Stack *stack) {
    if (stack->first == stack->last && stack->first->buffer_pt == 0) {
        printf("Error: nothing to pop from stack\n");
        return (NULL);
    } else if (stack->last->buffer_pt == 0) {
        stack_delete_last_node(stack);
    } else {
        stack->last->buffer_pt--;
    }
    return (stack->last->buffer[stack->last->buffer_pt]);
}

ret_type stack_push(Stack *stack, void *x) {
    stack->last->buffer[stack->last->buffer_pt] = x;
    if (stack->last->buffer_pt == STACK_BUFF_SIZE-1) {
        stack_new_node(&(stack->last->next));
        stack->last = stack->last->next;
    } else {
        stack->last->buffer_pt++;
    }
	return (OK);
}

bool stack_is_empty(Stack *stack) {
    if (stack->first == stack->last && stack->first->buffer_pt == 0) {
        return (TRUE);
    }
	return (FALSE);
}


void *stack_get_last(Stack *stack) {
    Stack_node *tmp;

    tmp = stack->last;
    if (stack_is_empty(stack)) {
        printf("Error: stack is empty\n");
        return (0);
    } else if (stack->last->buffer_pt == 0) {
        tmp = stack->first;
        while (tmp->next != stack->last) {
            tmp = tmp->next;
        }
        return (tmp->buffer[tmp->buffer_pt]);
    }
    return (tmp->buffer[(tmp->buffer_pt)-1]);
}
