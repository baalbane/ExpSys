/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:12:06 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/06 20:58:12 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		pop_parent(t_rpn_data *data)
{
	char		a;

	while ((a = *(char*)stack_pop(data->stack)) != '(')
	{
		if (a == 0)
		{
			printf("BIG ERROR\n");
			return (ERROR);
		}
		data->rpn[++(data->rpn_pt)] = a;
	}
	return (OK);
}

static int		get_ope_lvl(char a)
{
	char		*ptr;

	ptr = strchr(OPERANDS, a);
	if (ptr == NULL)
		return (-1);
	return ((int)(ptr - OPERANDS));
}

static char		rpn_cmp_op_lvl(t_rpn_data *data, char a)
{
	int			op_lvl;
	int			stack_lvl;

	op_lvl = get_ope_lvl(a);
	stack_lvl = get_ope_lvl(*(char*)stack_get_last(data->stack));
	if (op_lvl > stack_lvl)
		return (STACK_IS_LOWER);
	else if (op_lvl < stack_lvl)
		return (STACK_IS_HIGHTER);
	return (STACK_IS_EQUAL);
}

static int		rpn_init(t_rpn_data **to_init, char *line)
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

static int		rpn_cleanup(t_rpn_data *to_del)
{
	stack_delete(to_del->stack);
	free(to_del);
	return (OK);
}

char			*rpn_get(char *line)
{
	t_rpn_data	*data;
	int			i;
	char		*ret;

	rpn_init(&data, line);
	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] >= 'A' && line[i] <= 'Z')
			data->rpn[++(data->rpn_pt)] = line[i];
		else if (line[i] == '(')			
			stack_push(data->stack, ((void*)(line+i)));
		else if (line[i] == ')')
			pop_parent(data);
		else if (strchr(OPERANDS, line[i]) != NULL)
		{
			if (stack_is_empty(data->stack) == TRUE)
				stack_push(data->stack, ((void*)(line+i)));
			else if (rpn_cmp_op_lvl(data, line[i]) == STACK_IS_LOWER)
				stack_push(data->stack, ((void*)(line+i)));
			else if (rpn_cmp_op_lvl(data, line[i]) == STACK_IS_EQUAL)
			{
				data->rpn[++(data->rpn_pt)] = *(char*)stack_pop(data->stack);
				stack_push(data->stack, ((void*)(line+i)));
			}
			else
			{
				data->rpn[++(data->rpn_pt)] = *(char*)stack_pop(data->stack);
				i--;
			}
		}
	}
	while (stack_is_empty(data->stack) == FALSE)
		data->rpn[++(data->rpn_pt)] = *(char*)stack_pop(data->stack);
	data->rpn[++(data->rpn_pt)] = '\0';
	ret = data->rpn;
	rpn_cleanup(data);
	return (ret);
}
