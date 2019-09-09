
#include "main.h"

int  rpn_add_to_rpn(rpn_data *data, char to_add) {
    data->rpn[++(data->rpn_pt)] = to_add;
    return (1);
}

int pop(rpn_data *data) {
    if (data->stack_pt == -1) {
        return (0);
    }
    rpn_add_to_rpn(data, data->stack[data->stack_pt]);
    data->stack_pt--;
	return 1;
}

int pop_parent(rpn_data *data) {
	while (data->stack[data->stack_pt] != '(') {
		pop(data);
	}
	data->stack_pt--;
	return 1;
}


int push(rpn_data *data, char x) {
	data->stack[++data->stack_pt] = x;
	return 1;
}

int   stack_is_empty(rpn_data *data) {
	if (data->stack_pt == -1 || data->stack[data->stack_pt] == '(') {
		return (1);
	}
	return (0);
}

int  get_ope_lvl(char a) {
	char *ptr = strchr(OPERANDS, a);
	if (ptr == NULL) {
		return (-1);
	}
	return ((int)(ptr - OPERANDS));
}

int rpn_cmp_op_lvl(rpn_data *data, char a) {
    int op_lvl    = get_ope_lvl(a);
    int stack_lvl = get_ope_lvl(data->stack[data->stack_pt]);
    if (op_lvl > stack_lvl) {
        return (STACK_IS_LOWER);
    } else if (op_lvl < stack_lvl) {
        return (STACK_IS_HIGHTER);
    }
    return (STACK_IS_EQUAL);
}

int   rpn_init(rpn_data **to_init, char *line) {
    rpn_data *new;
    int       len;

    len = strlen(line);
    new = malloc(sizeof(rpn_data));
    new->rpn = malloc(sizeof(char) * (len + 1));
    new->rpn_pt = -1;

    new->stack_pt = -1;
    *to_init = new;
    return (1);
}

int  rpn_delete(rpn_data *to_del) {
    //free(rpn_data->stack);
    free(to_del);
    return (1);
}



char *rpn_get(char *line) {
    rpn_data  *data;
    int        i;

    rpn_init(&data, line);
	i = -1;
    while (line[++i]) {
        if (line[i] >= 'A' && line[i] <= 'Z') {
            rpn_add_to_rpn(data, line[i]);
		}
		else if (line[i] == '(') {
			push(data, line[i]);
		}
		else if (line[i] == ')') {
			pop_parent(data);
		}
		else if (strchr(OPERANDS, line[i]) != NULL) {
			if (stack_is_empty(data)) {
				push(data, line[i]);
			}
            else if (rpn_cmp_op_lvl(data, line[i]) == STACK_IS_LOWER) {
				push(data, line[i]);
			}
            else if (rpn_cmp_op_lvl(data, line[i]) == STACK_IS_EQUAL) {
				pop(data);
				push(data, line[i]);
			}
			else {
				pop(data);
				i--;
			}
		}
    }
    while (pop(data)) {
		;
	}
    data->rpn[++(data->rpn_pt)] = '\0';
    line = data->rpn;
    rpn_delete(data);
    return (line);
}

