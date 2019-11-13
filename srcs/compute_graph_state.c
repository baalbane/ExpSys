/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_graph_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:02:19 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/13 21:56:39 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		set_fact_value(t_fact *fact, int value)
{
	if (fact->set_value && value == 0)
	{
		printf("Error : Conflicting rules\n");
		exit(0);
	}
	if (fact->set_value == value)
		return (0);
	fact->set_value = value;
	return (1);
}

int				infer_node(t_node *node, int value)
{
	t_operand	*operand_node;
	int			left_result;
	int			right_result;

	if (!node)
		return (0);
	if (node->node_type == NODE_TYPE_FACT)
		return (set_fact_value((t_fact *)node, value));
	operand_node = (t_operand *)node;
	if (operand_node->operand_type == OPERAND_TYPE_AND)
	{
		left_result = infer_node(operand_node->left, value);
		right_result = infer_node(operand_node->right, value);
		return (left_result || right_result);
	}
	if (operand_node->operand_type == OPERAND_TYPE_NOT)
		return (infer_node(operand_node->left, !value));
	return (0);
}

int				compute_graph_state(t_graph *graph)
{
	int			i;
	int			state_has_changed;

	state_has_changed = 0;
	i = -1;
	while (graph->implications[++i])
		state_has_changed += evalute_implication(graph->implications[i]);
	if (state_has_changed)
		return (compute_graph_state(graph));
	return (OK);
}
