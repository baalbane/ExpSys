
#include "main.h"

graph  *new_graph() {
    graph *new;

    new = malloc(sizeof(graph));
    init_operand_list(new);
    init_fact_list(new);
    init_implication_list(new);
    return (new);
}


ret_type  add_new_node(graph *graph, nodes *to_add) {
    node_list   *list_ptr;
    int   *size;
    int   i;
    
    if (to_add->node_type == NODE_TYPE_FACT) {
        list_ptr = (node_list*)&(graph->facts);
        size = &(graph->fact_list_size);
    } else if (to_add->node_type == NODE_TYPE_OPERAND) {
        list_ptr = (node_list*)&(graph->operands);
        size = &(graph->operand_list_size);
    } else {
        list_ptr = (node_list*)&(graph->implications);
        size = &(graph->implication_list_size);
    }

    i = -1;
    while ((*list_ptr)[++i] != NULL) {
        ;
    }
    if (i == (*size) - 1) {
        printf("COULOUCOUCOU %d\n", *size);
        *size *= 2;
        printf("COULOUCOUCOU %d\n", *size);
        *list_ptr = realloc(*list_ptr, sizeof(void*) * *size);
        if (!(*list_ptr)) {
            printf("NOOOOOOOOOOOOO\n");
        }
    }
    (*list_ptr)[i] = to_add;
    (*list_ptr)[i + 1] = NULL;
    printf("ADD OK\n");
    return (OK);
}
