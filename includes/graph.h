/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:28:17 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/02 18:39:00 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

struct fact;
struct operand;

typedef struct				s_graph {
	struct fact				**facts;
	int						fact_list_size;
	struct operand			**operands;
	int						operand_list_size;
	struct t_implication	**implications;
	int						implication_list_size;
}							t_graph;

t_graph						*new_graph();
ret_type					add_new_node(t_graph *graph, nodes *node);

#endif
