/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:59:01 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/28 17:35:50 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	length(char *line);

char	**fdf_split(char *line, int i, int j, char **av)
{
	av = malloc(sizeof(char *) * (count_wd(line) +1));
	if (!av)
		return (NULL);
	while (*line)
	{
		while (*line < 33 && *line)
			line++;
		if (!*line)
			break ;
		av[i] = malloc(length(line) + 1);
		if (!av[i])
		{
			free_mem((void *)av, i -1);
			return (NULL);
		}
		j = 0;
		while (*line > 32)
			av[i][j++] = *line++;
		av[i][j] = '\0';
		i++;
	}
	av[i] = NULL;
	return (av);
}

static int	length(char *line)
{
	int	i;

	i = 0;
	while (*line > 32)
	{
		i++;
		line++;
	}
	return (i);
}

void	free_mem(void **av, int i)
{
	if (!av || !av[i])
		return ;
	while (i >= 0)
	{
		free(av[i]);
		i--;
	}
	free(av);
}

int	count_wd(char *line)
{
	int	i;

	i = 0;
	if (!line)
	{
		putstr("No content.\n");
		exit(3);
	}
	while (*line)
	{
		while (*line < 33 && *line)
			line++;
		if (!*line)
			return (i);
		i++;
		while (*line > 32)
			line++;
	}
	return (i);
}
