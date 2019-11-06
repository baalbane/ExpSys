/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:49:17 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/06 23:01:44 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char				stack_is_empty(t_stack *stack)
{
	if (stack->first == stack->last && stack->first->buffer_pt == 0)
		return (TRUE);
	return (FALSE);
}

void				*stack_pop(t_stack *stack)
{
	if (stack_is_empty(stack))
	{
		printf("Error: nothing to pop from stack\n");
		return (NULL);
	}
	else if (stack->last->buffer_pt == 0)
		stack_delete_last_node(stack);
	else
		stack->last->buffer_pt--;
	return (stack->last->buffer[stack->last->buffer_pt]);
}

int					stack_push(t_stack *stack, void *x)
{
	stack->last->buffer[stack->last->buffer_pt] = x;
	if (stack->last->buffer_pt == STACK_BUFF_SIZE - 1)
	{
		stack_new_node(&(stack->last->next));
		stack->last = stack->last->next;
	}
	else
		stack->last->buffer_pt++;
	return (OK);
}

void				*stack_get_last(t_stack *stack)
{
	t_stack_node *tmp;

	tmp = stack->last;
	if (stack_is_empty(stack))
	{
		printf("Error: stack is empty\n");
		return (0);
	}
	else if (stack->last->buffer_pt == 0)
	{
		tmp = stack->first;
		while (tmp->next != stack->last)
			tmp = tmp->next;
		return (tmp->buffer[tmp->buffer_pt]);
	}
	return (tmp->buffer[(tmp->buffer_pt) - 1]);
}
