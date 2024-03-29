/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:26:24 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/18 23:02:27 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int			has_valid_implication(char *line, char *double_implication)
{
	char			*ptr;

	ptr = strchr(line, '=');
	if (!ptr || ptr == line || *(ptr + 1) != '>')
		return (CRITICAL_ERROR);
	*double_implication = FALSE;
	if (ptr != line && *(ptr - 1) == '<')
		*double_implication = TRUE;
	return (OK);
}

static int			split_rule(char *line, char **left, char **right)
{
	*left = line;
	line = strchr(line, '=');
	*right = line + 2;
	if (*(line - 1) == '<')
		line--;
	*line = '\0';
	return (OK);
}

static t_node		*create_expr_from_rpn(t_graph *graph, char *rpn_string)
{
	t_node			*tmp;
	t_stack			*stack;
	int				i;

	tmp = NULL;
	stack = NULL;
	stack_new(&stack);
	i = -1;
	while (rpn_string[++i])
	{
		if (rpn_string[i] >= 'A' && rpn_string[i] <= 'Z')
			stack_push(stack, (void*)get_fact(graph, rpn_string[i]));
		else
			operand_new(graph, stack, rpn_string[i]);
	}
	tmp = (t_node*)stack_pop(stack);
	stack_delete(stack);
	return (tmp);
}

int					create_implication(t_graph *graph, char *left, char *right)
{
	t_implication	*new_implication;

	new_implication = implication_new(graph);
	new_implication->left = create_expr_from_rpn(graph, left);
	new_implication->right = create_expr_from_rpn(graph, right);
	return (0);
}

int					process_implication(char *line, t_graph *graph)
{
	char			*right;
	char			*left;
	char			has_double_implication;

	if (has_valid_implication(line, &has_double_implication) == CRITICAL_ERROR
	|| split_rule(line, &left, &right) == CRITICAL_ERROR)
		return (ft_error("Syntax error"));
	if (has_double_implication)
		check_line(left, 0);
	else
		check_line(left, 1);
	check_line(right, 0);
	left = rpn_get(left);
	right = rpn_get(right);
	create_implication(graph, left, right);
	if (has_double_implication == TRUE)
		create_implication(graph, right, left);
	free(left);
	free(right);
	return (OK);
}
