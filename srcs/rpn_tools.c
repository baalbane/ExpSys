
#include "main.h"

int				rpn_init(t_rpn_data **to_init, char *line)
{
	t_rpn_data	*new;
	int			len;

	len = strlen(line);
	new = malloc(sizeof(t_rpn_data));
	new->rpn = malloc(sizeof(char) * (len + 1));
	new->rpn_pt = -1;
	stack_new(&(new->stack));
	*to_init = new;
	return (OK);
}

int				rpn_cleanup(t_rpn_data *to_del)
{
	stack_delete(to_del->stack);
	free(to_del);
	return (OK);
}
