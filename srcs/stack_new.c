/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:00:53 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/06 23:04:43 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			stack_new_node(t_stack_node **node_ptr)
{
	t_stack_node	*new;

	if ((new = malloc(sizeof(t_stack_node))) == NULL)
	{
		printf("MALLOC ERROR\n");
		return (CRITICAL_ERROR);
	}
	new->buffer_pt = 0;
	new->next = NULL;
	*node_ptr = new;
	return (OK);
}

int					stack_new(t_stack **stack_ptr)
{
	t_stack			*new;

	if ((new = malloc(sizeof(t_stack))) == NULL)
	{
		printf("MALLOC ERROR\n");
		return (CRITICAL_ERROR);
	}
	if (stack_new_node(&(new->first)) != OK)
		return (CRITICAL_ERROR);
	new->last = new->first;
	*stack_ptr = new;
	return (OK);
}