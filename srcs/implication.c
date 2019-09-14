
#include "main.h"


implication *implication_new(graph *graph) {
    implication *new;

    new = malloc(sizeof(implication));
    new->node_type = NODE_TYPE_IMPLICATION;
    add_new_node(graph, (nodes*)new);
    return (new);
}

ret_type init_implication_list(graph *graph) {
    graph->implication_list_size = LIST_DEFAULT_SIZE;
    graph->implications = malloc(sizeof(implication*) * graph->implication_list_size);
    graph->implications[0] = NULL;
    return (OK);
}