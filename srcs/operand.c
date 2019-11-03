/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:24:50 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/03 18:24:54 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_operand		*operand_new(t_graph *graph, t_stack *stack, char operand_type)
{
	t_operand	*new;

	new = malloc(sizeof(t_operand));
	new->node_type = NODE_TYPE_OPERAND;
	new->right = NULL;
	new->operand_type = (strchr(OPERANDS, operand_type) - OPERANDS);
	if (new->operand_type == OPERAND_TYPE_AND
	|| new->operand_type == OPERAND_TYPE_OR
	|| new->operand_type == OPERAND_TYPE_XOR)
	{
		new->right = (t_node*)stack_pop(stack);
		new->left = (t_node*)stack_pop(stack);
	}
	if (new->operand_type == OPERAND_TYPE_XOR)
	{
		new->left = (t_node*)stack_pop(stack);
	}
	add_new_node(graph, (t_node*)new);
	stack_push(stack, (void*)new);
	return (new);
}

int				init_operand_list(t_graph *graph)
{
	graph->operand_list_size = LIST_DEFAULT_SIZE;
	graph->operands = malloc(sizeof(t_operand*) * graph->operand_list_size);
	graph->operands[0] = NULL;
	return (OK);
}
