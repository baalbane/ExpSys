/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:26:24 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/03 19:26:28 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int				has_valid_implication(char *line, char *has_double_implication)
{
	char				*ptr;

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

static int				split_rule(char *line, char **left, char **right)
{
	*left = line;
	line = strchr(line, '=');
	*right = line+2;
	if (*(line-1) == '<') {
		line--;
	}
	*line = '\0';
	return (OK);
}


static t_node			*create_expression_from_rpn(t_graph *graph, char *rpn_string)
{
	t_node				*tmp;
	t_stack				*stack;
	int					i;

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

int						process_implication(char *line, t_graph *graph)
{
	char				*right;
	char				*left;
	char				has_double_implication;
	t_implication		*new_implication;


	if (has_valid_implication(line, &has_double_implication) == CRITICAL_ERROR)
	{
		printf("ERROR SYNTAXE IN LINE \"%s\"", line);
		return (CRITICAL_ERROR);
	}
	if (split_rule(line, &left, &right) == CRITICAL_ERROR)
	{
		printf("CRITICAL ERROR IN LINE \"%s\"", line);
		return (CRITICAL_ERROR);
	}
	left = rpn_get(left);
	right = rpn_get(right);
	new_implication = implication_new(graph);
	new_implication->left = create_expression_from_rpn(graph, left);
	new_implication->right = create_expression_from_rpn(graph, right);
	if (has_double_implication == TRUE)
	{
		new_implication = implication_new(graph);
		new_implication->left = create_expression_from_rpn(graph, right);
		new_implication->right = create_expression_from_rpn(graph, left);
	}
	free(left);
	free(right);
	return (OK);
}
