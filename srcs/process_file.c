
#include "main.h"


ret_type    is_double_implies(char *line, bool *double_implies) {
    char *ptr;

    ptr = strchr(line, '=');
    if (!ptr || ptr == line || *(ptr+1) != '>') {
        return (CRITICAL_ERROR);
    }
    *double_implies = FALSE;
    if (*(ptr-1) == '<') {
        *double_implies = TRUE;
    }
    return (OK);
}

ret_type    split_rule(char *line, char **left, char **right) {
    char *ptr;

    *left = line;
    line = strchr(line, '=');
    *right = line+2;
    if (*(line-1) == '<') {
        line--;
    }
    *line = '\0';
    return (OK);
}

ret_type    process_line(char *line, operand_list *operands, fact_list *facts) {
    char                *right;
    char                *left;
    bool                 double_implie;

    printf("\nnew line: %s\n\n", line);

    if (is_double_implies(line, &double_implie) == CRITICAL_ERROR) {
        printf("ERROR SYNTAXE IN LINE \"%s\"", line);
        return (CRITICAL_ERROR);
    }
    if (split_rule(line, &left, &right) == CRITICAL_ERROR) {
        printf("CRITICAL ERROR IN LINE \"%s\"", line);
        return (CRITICAL_ERROR);
    }
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