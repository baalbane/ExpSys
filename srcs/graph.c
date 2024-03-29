/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:06:15 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/18 22:05:47 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_graph			*new_graph(void)
{
	t_graph		*new;

	new = ft_malloc(sizeof(t_graph));
	init_operand_list(new);
	init_fact_list(new);
	init_implication_list(new);
	return (new);
}

t_node_list		*get_node_list(t_graph *graph, char type)
{
	if (type == NODE_TYPE_FACT)
		return ((t_node_list*)&(graph->facts));
	else if (type == NODE_TYPE_OPERAND)
		return ((t_node_list*)&(graph->operands));
	return ((t_node_list*)&(graph->implications));
}

int				*get_node_list_size(t_graph *graph, char type)
{
	if (type == NODE_TYPE_FACT)
		return (&(graph->fact_list_size));
	else if (type == NODE_TYPE_OPERAND)
		return (&(graph->operand_list_size));
	return (&(graph->implication_list_size));
}

int				add_new_node(t_graph *graph, t_node *to_add)
{
	t_node_list	*list_ptr;
	int			*size;
	int			i;

	list_ptr = get_node_list(graph, to_add->node_type);
	size = get_node_list_size(graph, to_add->node_type);
	i = -1;
	while ((*list_ptr)[++i] != NULL)
	{
		;
	}
	if (i == (*size) - 1)
	{
		*size *= 2;
		*list_ptr = realloc(*list_ptr, sizeof(void*) * *size);
	}
	(*list_ptr)[i] = to_add;
	(*list_ptr)[i + 1] = NULL;
	return (OK);
}
