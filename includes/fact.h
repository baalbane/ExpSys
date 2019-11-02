/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:52:52 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/02 18:44:29 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACT_H
# define FACT_H

struct operand;

typedef struct	s_fact
{
	char		node_type;
	char		name;

	char		initial_value;
	char		set_value;
}				t_fact;

typedef t_fact	**t_fact_list;

t_fact			*fact_new(t_graph *graph, char name);
ret_type		init_fact_list(t_graph *graph);
t_fact			*get_fact(t_graph *graph, char name);

#endif
