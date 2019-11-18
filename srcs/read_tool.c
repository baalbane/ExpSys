/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:42:58 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/18 23:19:14 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			check_line(char *line, int left)
{
	int		i;
	char	last;

	i = -1;
	last = 0;
	check_parenthesis_coherence(line);
	while (line[++i])
	{
		check_char(line[i], last, left);
		last = line[i];
	}
	if ((last < 'A' || last > 'Z') && last != ')')
		ft_error("wrong last character");
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

	new_line = ft_malloc(sizeof(char) * (count_non_whitespace(*line) + 1));
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
