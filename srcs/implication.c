/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implication.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:54:42 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/18 22:04:44 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_implication		*implication_new(t_graph *graph)
{
	t_implication	*new;

	new = ft_malloc(sizeof(t_implication));
	new->node_type = NODE_TYPE_IMPLICATION;
	new->last_left_value = 0;
	add_new_node(graph, (t_node*)new);
	return (new);
}

int					init_implication_list(t_graph *graph)
{
	size_t size;

	graph->implication_list_size = LIST_DEFAULT_SIZE;
	size = graph->implication_list_size;
	graph->implications = ft_malloc(sizeof(t_implication*) * size);
	graph->implications[0] = NULL;
	return (OK);
}
