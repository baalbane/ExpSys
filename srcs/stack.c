
#include "main.h"



static int stack_new_node(t_stack_node **node_ptr) {
    t_stack_node *new;

     if ((new = malloc(sizeof(t_stack_node))) == NULL) {
        printf("MALLOC ERROR\n");
        return (CRITICAL_ERROR);
    }
    new->buffer_pt = 0;
    new->next = NULL;
    *node_ptr = new;
    return (OK);
}



int stack_new(t_stack **stack_ptr) {
    t_stack *new;

    if ((new = malloc(sizeof(t_stack))) == NULL) {
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

static int stack_delete_node(t_stack_node *to_del) {
    if (to_del->next) {
        stack_delete_node(to_del->next);
    }
    free(to_del);
    return (OK);
}

int stack_delete(t_stack *to_del) {
    stack_delete_node(to_del->first);
    free(to_del);
    return (OK);
}

static int stack_delete_last_node(t_stack *stack) {
    t_stack_node *tmp;

    tmp = stack->first;
    while (tmp->next != stack->last) {
        tmp = tmp->next;
    }
    free(stack->last);
    tmp->next = NULL;
    stack->last = tmp;
    return (OK);
}

void *stack_pop(t_stack *stack) {
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

int stack_push(t_stack *stack, void *x) {
    stack->last->buffer[stack->last->buffer_pt] = x;
    if (stack->last->buffer_pt == STACK_BUFF_SIZE-1) {
        stack_new_node(&(stack->last->next));
        stack->last = stack->last->next;
    } else {
        stack->last->buffer_pt++;
    }
	return (OK);
}

char stack_is_empty(t_stack *stack) {
    if (stack->first == stack->last && stack->first->buffer_pt == 0) {
        return (TRUE);
    }
	return (FALSE);
}


void *stack_get_last(t_stack *stack) {
    t_stack_node *tmp;

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
