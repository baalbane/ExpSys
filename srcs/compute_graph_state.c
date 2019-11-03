/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_graph_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:02:19 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/03 16:26:51 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int				evaluate_expression(int left, int right, char operand)
{
	if (operand == OPERAND_TYPE_AND)
		return (right && left);
	if (operand == OPERAND_TYPE_OR)
		return (right || left);
	if (operand == OPERAND_TYPE_XOR)
		return (right ^ left);
	if (operand == OPERAND_TYPE_NOT)
		return (!left);
	return (-1);
}

static int		evalute_node(t_node *node)
{
	t_operand	*operand_node;
	int			right;
	int			left;

	if (!node)
		return (0);
	if (node->node_type == NODE_TYPE_FACT)
		return (((t_fact *)node)->set_value);
	operand_node = (t_operand *)node;
	right = evalute_node(operand_node->right);
	left = evalute_node(operand_node->left);
	return (evaluate_expression(left, right, operand_node->operand_type));
}

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

static int		infer_node(t_node *node, int value)
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

static int		evalute_implication(t_implication *implication)
{
	if (evalute_node(implication->left))
		return (infer_node(implication->right, 1));
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
