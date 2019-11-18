/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expression_validity.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:04:54 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/18 23:19:43 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			check_parenthesis_coherence(char *line)
{
	int		count;

	count = 0;
	while (*line)
	{
		if (*line == '(')
			count++;
		else if (*line == ')')
			count--;
		if (count < 0 || (*line == '=' && count != 0))
			ft_error("Parenthesis error");
		line++;
	}
	if (count != 0)
		ft_error("Parenthesis error");
	return (1);
}

int			check_parenthesis(char current, char last, int left)
{
	if (!left)
		ft_error("parenthesis in conclusion");
	if (current == '(' && !strchr("+|^!(", last))
		ft_error("missing operand");
	if (current == ')')
		if ((last != ')' && (last < 'A' || last > 'Z')))
			ft_error("missing operand");
	return (0);
}

int			check_char(char current, char last, int left)
{
	if (current >= 'A' && current <= 'Z')
	{
		if ((last >= 'A' && last <= 'Z') || last == ')')
			ft_error("Multi fact error");
	}
	else if (current == '!')
	{
		if (last != 0 && strchr("+|^(", last) == NULL)
			ft_error("wrong negation");
	}
	else if (strchr("+|^", current))
	{
		if (last != ')' && ((!left && (current == '|' || \
		current == '^')) || last < 'A' || last > 'Z'))
			ft_error("wrong rule");
	}
	else if (current == '(' || current == ')')
		check_parenthesis(current, last, left);
	else
		ft_error("Unknow character");
	return (1);
}
