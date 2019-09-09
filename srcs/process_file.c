
#include "main.h"

ret_type    process_line(char *line, operand_list *operands, fact_list *facts) {
    char                *right;
    char                *left;
    bool                 double_implie;

    if (has_valid_implication(line, &double_implie) == CRITICAL_ERROR) {
        printf("ERROR SYNTAXE IN LINE \"%s\"", line);
        return (CRITICAL_ERROR);
    }
    if (split_rule(line, &left, &right) == CRITICAL_ERROR) {
        printf("CRITICAL ERROR IN LINE \"%s\"", line);
        return (CRITICAL_ERROR);
    }
    left = rpn_get(left);
    right = rpn_get(right);
    printf("double implie: %d\n", double_implie);
    printf("left : \"%s\"\n", left);
    printf("right: \"%s\"\n", right);
    return (OK);
}

ret_type process_file(char *file_name, operand_list *operands, fact_list *facts) {
    char    *new_line;

    if (init_read(file_name) != OK) {
        return (CRITICAL_ERROR);
    }
    while (get_new_line(&new_line) == OK) {
        if (new_line[0] != '\0' && process_line(new_line, operands, facts) == CRITICAL_ERROR) {
            free(new_line);
            return (CRITICAL_ERROR);
        }
        free(new_line);
    }
    cleanup_read();
    return (OK);
}