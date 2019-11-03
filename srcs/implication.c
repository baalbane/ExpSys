/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implication.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:54:42 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/03 16:26:53 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_implication		*implication_new(t_graph *graph)
{
	t_implication	*new;

	new = malloc(sizeof(t_implication));
	new->node_type = NODE_TYPE_IMPLICATION;
	add_new_node(graph, (t_node*)new);
	return (new);
}

int					init_implication_list(t_graph *graph)
{
	size_t size;

	size = graph->implication_list_size;
	graph->implication_list_size = LIST_DEFAULT_SIZE;
	graph->implications = malloc(sizeof(t_implication*) * size);
	graph->implications[0] = NULL;
	return (OK);
}
