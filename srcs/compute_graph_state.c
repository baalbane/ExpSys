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

int			evaluate_expression(int left_value, int right_value, char operand) {
    if (operand == OPERAND_TYPE_AND) {
        return (right_value && left_value);
    }
    if (operand == OPERAND_TYPE_OR) {
        return (right_value || left_value);
    }
    if (operand == OPERAND_TYPE_XOR) {
        return (right_value ^ left_value);
    }
    if (operand == OPERAND_TYPE_NOT) {
        return (!left_value);
    }
	return (-1);
}

static int   evalute_node(t_node *node) {
    t_operand *operand_node;
    int      right_value;
    int      left_value;
    
    if (!node) {
        return (0);
    }
    if (node->node_type == NODE_TYPE_FACT) {
        return (((t_fact *)node)->set_value);
    }
    operand_node = (t_operand *)node;
    right_value = evalute_node(operand_node->right);
    left_value = evalute_node(operand_node->left);
    return (evaluate_expression(left_value, right_value, operand_node->operand_type));
}

static int				set_fact_value(t_fact *fact, int value) {
	if (fact->set_value && value == 0) {
		printf("Error : Conflicting rules\n");
		exit(0);
	}
	if (fact->set_value == value) {
		return (0);
	}
	fact->set_value = value;
	return (1);
}

static int             infer_node(t_node *node, int value) {
    t_operand *operand_node;
    
    if (!node) {
        return (0);
    }
    if (node->node_type == NODE_TYPE_FACT) {
		return (set_fact_value((t_fact *)node, value));
    }
    operand_node = (t_operand *)node;
    if (operand_node->operand_type == OPERAND_TYPE_AND) {
        int left_result = infer_node(operand_node->left, value);
        int right_result = infer_node(operand_node->right, value);
        return (left_result || right_result);
    }
    if (operand_node->operand_type == OPERAND_TYPE_NOT) {
        return (infer_node(operand_node->left, !value));
    }
    return (0);
}

static int   evalute_implication(t_implication *implication) {
    if (evalute_node(implication->left)) {
        return (infer_node(implication->right, 1));
    }
    return (0);
}

int compute_graph_state(t_graph *graph) {
    int i;
    int state_has_changed = 0;

    for (i = 0; graph->implications[i]; i++) {
        state_has_changed += evalute_implication(graph->implications[i]);
    }
    if (state_has_changed) {
        return (compute_graph_state(graph));
    }
    return (OK);
}
