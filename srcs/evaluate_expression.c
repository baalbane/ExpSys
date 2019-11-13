
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

int				evalute_node(t_node *node)
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

int				evalute_implication(t_implication *implication)
{
	if (evalute_node(implication->left))
		return (infer_node(implication->right, 1));
	return (0);
}
