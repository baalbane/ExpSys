
#include "main.h"

graph			*new_graph() {
    graph		*new;

    new = malloc(sizeof(graph));
    init_operand_list(new);
    init_fact_list(new);
    init_implication_list(new);
    return (new);
}

node_list		*get_node_list(graph *graph, NODE_TYPE type) {
    if (type == NODE_TYPE_FACT) {
        return ((node_list*)&(graph->facts));
    }
	else if (type == NODE_TYPE_OPERAND) {
        return ((node_list*)&(graph->operands));
	return ((node_list*)&(graph->implications));
}

int				*get_node_list_size(graph *graph, NODE_TYPE type) {
    if (type == NODE_TYPE_FACT) {
        return (&(graph->fact_list_size));
    }
	else if (type == NODE_TYPE_OPERAND) {
        return (&(graph->operand_list_size));
	return (&(graph->implication_list_size));
}


ret_type		add_new_node(graph *graph, nodes *to_add) {
    node_list	*list_ptr;
    int   		*size;
    int			i;
    
	list_ptr = get_node_list(graph, to_add->node_type);
	size = get_node_list_size(graph, to_add->node_type);

    i = -1;
    while ((*list_ptr)[++i] != NULL) {
        ;
    }
    if (i == (*size) - 1) {
        *size *= 2;
        *list_ptr = realloc(*list_ptr, sizeof(void*) * *size);
    }
    (*list_ptr)[i] = to_add;
    (*list_ptr)[i + 1] = NULL;
    return (OK);
}
