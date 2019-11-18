/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:34:40 by baalbane          #+#    #+#             */
/*   Updated: 2019/11/18 22:05:36 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static FILE *g_file = NULL;
static char *g_buffer = NULL;

int			cleanup_read(void)
{
	if (g_file)
	{
		fclose(g_file);
		g_file = NULL;
	}
	if (g_buffer)
	{
		free(g_buffer);
		g_buffer = NULL;
	}
	return (OK);
}

int			init_read(char *file_name)
{
	cleanup_read();
	if ((g_file = fopen(file_name, "r")) == NULL)
	{
		printf("ERROR: file \"%s\" doesn't exist\n", file_name);
		return (ERROR);
	}
	g_buffer = ft_malloc(sizeof(char));
	g_buffer[0] = '\0';
	return (OK);
}

static int	return_line(char **line)
{
	char	*old_buffer;
	char	*ptr;

	ptr = strchr(g_buffer, '\n');
	if (!ptr)
		ptr = g_buffer + strlen(g_buffer);
	old_buffer = g_buffer;
	if (*ptr == '\0')
	{
		g_buffer = ft_malloc(sizeof(char));
		g_buffer[0] = '\0';
	}
	else
	{
		g_buffer = ft_malloc(sizeof(char) * (strlen(ptr + 1) + 1));
		strcpy(g_buffer, ptr + 1);
	}
	*ptr = '\0';
	*line = ft_malloc(sizeof(char) * (strlen(old_buffer) + 1));
	strcpy(*line, old_buffer);
	free(old_buffer);
	remove_space(line);
	return (OK);
}

static int	read_buffer(void)
{
	char	*new_buffer;
	int		read_size;
	char	read_buffer[READ_BUFF_SIZE + 1];

	read_size = fread(read_buffer, sizeof(char), READ_BUFF_SIZE, g_file);
	if (read_size <= 0)
		return (READ_EOF);
	read_buffer[read_size] = '\0';
	new_buffer = ft_malloc(sizeof(char) * (strlen(g_buffer) + read_size + 1));
	strcpy(new_buffer, g_buffer);
	strcat(new_buffer, read_buffer);
	free(g_buffer);
	g_buffer = new_buffer;
	return (OK);
}

int			get_new_line(char **line)
{
	int		ret;

	ret = OK;
	while (ret == OK)
	{
		if (strchr(g_buffer, '\n') != NULL)
			return (return_line(line));
		ret = read_buffer();
	}
	if (g_buffer[0] != '\0')
		return (return_line(line));
	return (READ_EOF);
}
