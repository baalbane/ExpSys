
#include "main.h"


fact *fact_new(graph *graph, char name) {
    fact *new;

    new = malloc(sizeof(fact));
    new->node_type = NODE_TYPE_FACT;
    new->name = name;
    new->initial_value = 0;
    new->set_value = 0;
    add_new_node(graph, (nodes*)new);
    return (new);
}

fact *get_fact(graph *graph, char name) {
    int     i;

    i = -1;
    while (graph->facts[++i]) {
        if (((fact*)(graph->facts[i]))->name == name) {
            return (((fact*)(graph->facts[i])));
        }
    }
    return (fact_new(graph, name));
}

ret_type init_fact_list(graph *graph) {
    graph->fact_list_size = LIST_DEFAULT_SIZE;
    graph->facts = malloc(sizeof(fact*) * graph->fact_list_size);
    graph->facts[0] = NULL;
    return (OK);
}
