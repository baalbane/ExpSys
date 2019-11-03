/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:28:17 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/03 16:34:59 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

struct s_fact;
struct s_operand;

typedef struct				s_graph {
	struct s_fact			**facts;
	int						fact_list_size;
	struct s_operand		**operands;
	int						operand_list_size;
	struct s_implication	**implications;
	int						implication_list_size;
}							t_graph;

t_graph						*new_graph();
int							add_new_node(t_graph *graph, t_node *node);

#endif
