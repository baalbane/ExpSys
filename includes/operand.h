/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:52:39 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/03 16:42:42 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_H
# define OPERAND_H

# define OPERAND_TYPE_XOR 0
# define OPERAND_TYPE_OR 1
# define OPERAND_TYPE_AND 2
# define OPERAND_TYPE_NOT 3
# define NB_OPERAND_TYPE 4

struct s_node;

typedef struct		s_operand
{
	char			node_type;
	char			operand_type;
	struct s_node	*right;
	struct s_node	*left;
}					t_operand;

typedef t_operand	**t_operand_list;

t_operand			*operand_new(t_graph *graph, t_stack *stack,\
					char operand_type);
int					init_operand_list(t_graph *graph);

#endif
