
#include "main.h"


static ret_type set_initial_value(graph *graph, char *line) {
    int    i;
    fact  *tmp;

    i = 0;
    while (line[++i]) {
        tmp = get_fact(graph, line[i]);
        if (!tmp) {
            printf("ERROR: Unknown fact: '%c'\n", line[i]);
            return (ERROR);
        }
        tmp->set_value = 1;
    }
    return (OK);
}

static ret_type print_result(graph *graph, char *line) {
    int    i;
    fact  *tmp;

    i = 0;
    while (line[++i]) {
        tmp = get_fact(graph, line[i]);
        if (!tmp) {
            printf("ERROR: Unknown fact: '%c'\n", line[i]);
            return (ERROR);
        }
        printf("%c = %d\n", tmp->name, tmp->set_value);
    }
    return (OK);
}


static ret_type process_line(char *line, graph *graph) {
    if (line[0] == '?') {
        compute_graph_state(graph);
        print_result(graph, line);
        return (OK);
    } else if (line[0] == '=') {
        if (set_initial_value(graph, line) != OK) {
            return (ERROR);
        }
        return (OK);
    }
    return (process_implication(line, graph));
}

ret_type process_file(char *file_name, graph *graph) {
    char    *new_line;

    if (init_read(file_name) != OK) {
        return (CRITICAL_ERROR);
    }
    while (get_new_line(&new_line) == OK) {
        if (new_line[0] != '\0' && process_line(new_line, graph) == CRITICAL_ERROR) {
            free(new_line);
            return (CRITICAL_ERROR);
        }
        free(new_line);
    }
    cleanup_read();
    return (OK);
}