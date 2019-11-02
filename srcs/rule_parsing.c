
#include "main.h"

static ret_type has_valid_implication(char *line, bool *has_double_implication) {
    char *ptr;

    ptr = strchr(line, '=');
    if (!ptr || ptr == line || *(ptr+1) != '>') {
        return (CRITICAL_ERROR);
    }
    *has_double_implication = FALSE;
    if (*(ptr-1) == '<') {
        *has_double_implication = TRUE;
    }
    return (OK);
}

static ret_type split_rule(char *line, char **left, char **right) {
    *left = line;
    line = strchr(line, '=');
    *right = line+2;
    if (*(line-1) == '<') {
        line--;
    }
    *line = '\0';
    return (OK);
}


static nodes    *create_expression_from_rpn(t_graph *graph, char *rpn_string) {
    nodes *tmp = NULL;
    Stack   *stack = NULL;
    int i;

    stack_new(&stack);

    for (i = 0; rpn_string[i]; i++) {
        if (rpn_string[i] >= 'A' && rpn_string[i] <= 'Z') {
            stack_push(stack, (void*)get_fact(graph, rpn_string[i]));
        } else {
            operand_new(graph, stack, rpn_string[i]);
        }
    }
    tmp = (nodes*)stack_pop(stack);
    stack_delete(stack);
    return (tmp);
}

ret_type process_implication(char *line, t_graph *graph) {
    char                *right;
    char                *left;
    bool                 has_double_implication;



    printf("PROCESING LINE \"%s\"\n", line);
    if (has_valid_implication(line, &has_double_implication) == CRITICAL_ERROR) {
        printf("ERROR SYNTAXE IN LINE \"%s\"", line);
        return (CRITICAL_ERROR);
    }
    if (split_rule(line, &left, &right) == CRITICAL_ERROR) {
        printf("CRITICAL ERROR IN LINE \"%s\"", line);
        return (CRITICAL_ERROR);
    }
    left = rpn_get(left);
    right = rpn_get(right);
    printf("double implie: %d\n", has_double_implication);
    printf("left : \"%s\"\n", left);
    printf("right: \"%s\"\n", right);


    implication *new_implication;

    new_implication = implication_new(graph);
    new_implication->left = create_expression_from_rpn(graph, left);
    new_implication->right = create_expression_from_rpn(graph, right);

    if (has_double_implication == TRUE) {
        new_implication = implication_new(graph);
        new_implication->left = create_expression_from_rpn(graph, right);
        new_implication->right = create_expression_from_rpn(graph, left);
    }

    free(left);
    free(right);
    return (OK);
}
