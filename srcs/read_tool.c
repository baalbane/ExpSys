/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:42:58 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/13 23:02:14 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			check_parenthesis(char *line)
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

int			check_char(char current, char last, int left)
{
	if (current >= 'A' && current <= 'Z')
	{
		if ((last >= 'A' && last <= 'Z') || last == ')')
			ft_error("Multi fact error");
	}
	else if (current == '!')
	{
		if (last != 0 && strchr("+|^)", last))
			ft_error("Error: wrong negation");
	}
	else if (strchr("+|^", current))
	{
		if (last != ')' && ((!left && (current == '|' || current == '^')) || last < 'A' || last > 'Z'))
			ft_error("Error: wrong rule");
	}
	else if (current == '(')
	{
		if (!left || !strchr("+|^!(", last))
			ft_error("Error: missing operator");
	}
	else if (current == ')')
	{
		if (!left || (last != ')' && last < 'A' && last > 'Z'))
			ft_error("Error: missing operand");
	}
	else
		ft_error("Unknow character");
	return (1);
}

int			check_line(char *line, int left)
{
	int		i;
	char	last;

	i = -1;
	last = 0;
	while (line[++i])
	{
		check_char(line[i], last, left);
		last = line[i];
	}
	if ((last < 'A' || last > 'Z') && last != ')')
		ft_error("Error: wrong last character");
	return (1);
}

int			count_non_whitespace(char *line)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (line[i] != '\0' && line[i] != '#')
	{
		if (line[i] != ' ' && line[i] != '\t')
			count++;
		i++;
	}
	return (count);
}

int			remove_space(char **line)
{
	char	*new_line;
	int		len;
	int		i;

	new_line = malloc(sizeof(char) * (count_non_whitespace(*line) + 1));
	i = 0;
	len = 0;
	while ((*line)[i] != '\0' && (*line)[i] != '#')
	{
		if ((*line)[i] == '!' && (*line)[i + 1] == '!')
			i++;
		else if ((*line)[i] != ' ' && (*line)[i] != '\t')
			new_line[len++] = (*line)[i];
		i++;
	}
	new_line[len] = '\0';
	free(*line);
	*line = new_line;
	return (OK);
}
