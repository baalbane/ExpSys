/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:46:25 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/03 16:27:16 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_fact		*fact_new(t_graph *graph, char name)
{
	t_fact	*new;

	new = malloc(sizeof(t_fact));
	new->node_type = NODE_TYPE_FACT;
	new->name = name;
	new->initial_value = 0;
	new->set_value = 0;
	add_new_node(graph, (t_node*)new);
	return (new);
}

t_fact		*get_fact(t_graph *graph, char name)
{
	int		i;

	i = -1;
	while (graph->facts[++i])
	{
		if (((t_fact*)(graph->facts[i]))->name == name)
			return (((t_fact*)(graph->facts[i])));
	}
	return (fact_new(graph, name));
}

int			init_fact_list(t_graph *graph)
{
	graph->fact_list_size = LIST_DEFAULT_SIZE;
	graph->facts = malloc(sizeof(t_fact*) * graph->fact_list_size);
	graph->facts[0] = NULL;
	return (OK);
}
