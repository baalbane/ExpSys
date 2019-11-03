/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:31:58 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/03 18:32:00 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	set_initial_value(t_graph *graph, char *line)
{
	int		i;
	t_fact	*tmp;

	i = 0;
	while (line[++i])
	{
		tmp = get_fact(graph, line[i]);
		if (!tmp)
		{
			printf("ERROR: Unknown fact: '%c'\n", line[i]);
			return (ERROR);
		}
		tmp->set_value = 1;
	}
	return (OK);
}

static int	print_result(t_graph *graph, char *line)
{
	int		i;
	t_fact	*tmp;

	i = 0;
	while (line[++i])
	{
		tmp = get_fact(graph, line[i]);
		if (!tmp)
		{
			printf("ERROR: Unknown fact: '%c'\n", line[i]);
			return (ERROR);
		}
		printf("%c = %d\n", tmp->name, tmp->set_value);
	}
	return (OK);
}

static int	process_line(char *line, t_graph *graph)
{
	if (line[0] == '?')
	{
		compute_graph_state(graph);
		print_result(graph, line);
		return (OK);
	}
	else if (line[0] == '=')
	{
		if (set_initial_value(graph, line) != OK)
			return (ERROR);
		return (OK);
	}
	return (process_implication(line, graph));
}

int			process_file(char *file_name, t_graph *graph)
{
	char	*new_line;

	if (init_read(file_name) != OK)
		return (CRITICAL_ERROR);
	while (get_new_line(&new_line) == OK)
	{
		if (new_line[0] != '\0'
		&& process_line(new_line, graph) == CRITICAL_ERROR)
		{
			free(new_line);
			return (CRITICAL_ERROR);
		}
		free(new_line);
	}
	cleanup_read();
	return (OK);
}
