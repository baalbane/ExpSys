/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 22:59:34 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/06 23:04:38 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


int			stack_delete_node(t_stack_node *to_del)
{
	if (to_del->next)
		stack_delete_node(to_del->next);
	free(to_del);
	return (OK);
}

int					stack_delete(t_stack *to_del)
{
	stack_delete_node(to_del->first);
	free(to_del);
	return (OK);
}

int			stack_delete_last_node(t_stack *stack)
{
	t_stack_node	*tmp;

	tmp = stack->first;
	while (tmp->next != stack->last)
		tmp = tmp->next;
	free(stack->last);
	tmp->next = NULL;
	stack->last = tmp;
	return (OK);
}
