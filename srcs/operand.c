
#include "main.h"


operand *operand_new(graph *graph, Stack *stack, char operand_type) {
    operand *new;

    new = malloc(sizeof(operand));
    new->node_type = NODE_TYPE_OPERAND;
    new->right = NULL;
    new->operand_type = (strchr(OPERANDS, operand_type)-OPERANDS);
    switch (new->operand_type) {
        case OPERAND_TYPE_AND:
        case OPERAND_TYPE_OR:
        case OPERAND_TYPE_XOR:
            new->right = (nodes*)stack_pop(stack);
        case OPERAND_TYPE_NOT:
            new->left = (nodes*)stack_pop(stack);
    }    
    add_new_node(graph, (nodes*)new);
    stack_push(stack, (void*)new);
    return (new);
}

ret_type init_operand_list(graph *graph) {
    graph->operand_list_size = LIST_DEFAULT_SIZE;
    graph->operands = malloc(sizeof(operand*) * graph->operand_list_size);
    graph->operands[0] = NULL;
    return (OK);
}