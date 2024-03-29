/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implication.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:41:04 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/13 21:53:45 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPLICATION_H
# define IMPLICATION_H

struct s_node;

typedef struct			s_implication {
	char				node_type;
	char				last_left_value;
	struct s_node		*left;
	struct s_node		*right;
}						t_implication;

typedef t_implication	**t_implication_list;

t_implication			*implication_new(t_graph *graph);
int						init_implication_list(t_graph *graph);

#endif
