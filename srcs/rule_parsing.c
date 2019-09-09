
#include "main.h"

ret_type    has_valid_implication(char *line, bool *has_double_implication) {
	char	*implication;
	
	*has_double_implication = strstr(line, "<=>") != NULL;
	implication = strstr(line, "=>");
	if (!implication || (implication - line <= has_double_implication) || !*(implication + 2)) {
        return (CRITICAL_ERROR);
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
