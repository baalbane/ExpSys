/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:03:00 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/06 23:03:33 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define STACK_BUFF_SIZE 1

typedef struct			s_stack_node {
	void				*buffer[STACK_BUFF_SIZE];
	int					buffer_pt;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct			s_stack {
	t_stack_node		*first;
	t_stack_node		*last;
}						t_stack;

int						stack_new(t_stack **stack_ptr);
int						stack_delete(t_stack *to_del);
int						stack_delete_last_node(t_stack *stack);
int						stack_new_node(t_stack_node **node_ptr);
void					*stack_pop(t_stack *stack);
int						stack_push(t_stack *stack, void *x);
char					stack_is_empty(t_stack *stack);
void					*stack_get_last(t_stack *stack);

#endif
