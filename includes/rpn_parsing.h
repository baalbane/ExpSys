/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:03:00 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/03 16:40:34 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_PARSING_H
# define RPN_PARSING_H

# define STACK_IS_LOWER -1
# define STACK_IS_EQUAL 0
# define STACK_IS_HIGHTER 1

typedef struct	s_rpn_data
{
	char		*rpn;
	int			rpn_pt;
	t_stack		*stack;
}				t_rpn_data;

char			*rpn_get(char *line);

#endif
