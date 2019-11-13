
#include "main.h"

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
