/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implication.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:41:04 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/02 18:41:26 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPLICATION_H
# define IMPLICATION_H

struct	nodes;

typedef struct	t_implication
{
    char		node_type;
    nodes		*left;
    nodes		*right;
}				implication, **implication_list;


implication		*implication_new(t_graph *graph);
ret_type		init_implication_list(t_graph *graph);

#endif