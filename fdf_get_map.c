/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:17:34 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/27 18:19:57 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_atoi(char *s, char **colors);
static int	check_atoi(char *s);
static int	get_line(t_point **map, int wd, char **av, int x);

int	open_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		perror("Could not open file");
		exit(2);
	}
	return (fd);
}

t_point	**get_map(char *file, int wd, int ht)
{
	int			fd;
	char		*line;
	static char	*backup;
	char		**av;
	t_point		**map;

	map = malloc(sizeof(t_point *) * (ht));
	if (!map)
		exit(5);
	fd = open_file(file);
	line = get_next_line(fd, &backup);
	while (line && line[0] != '\0')
	{
		av = fdf_split(line, 0, 0, NULL);
		if (!get_line(map, wd, av, 0))
			free_line(line, backup, 3);
		free(line);
		line = get_next_line(fd, &backup);
	}
	if (line)
		free(line);
	close(fd);
	return (map);
}

static int	get_line(t_point **map, int wd, char **av, int x)
{
	int			z;
	static int	y;
	char		*colors;

	map[y] = malloc(sizeof(t_point) * (wd));
	if (!map[y])
	{
		free_map(map, y -1, av, wd -1);
		return (0);
	}
	while (av[x])
	{
		colors = NULL;
		z = ft_atoi(av[x], &colors);
		if (z == 0 && !(av[x][0] == '0'
			&& (av[x][1] == '\0' || av[x][1] == ',')))
		{
			free_map(map, y, av, wd -1);
			return (0);
		}
		map[y][x].z = z;
		get_colors(map, y, x, colors);
		x++;
	}
	free_mem((void **)av, wd -1);
	y++;
	return (1);
}

static int	ft_atoi(char *s, char **colors)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (!check_atoi(s))
		return (0);
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	if (*s && *s != ',')
		return (0);
	if (*s == ',')
		*colors = s + 1;
	n *= sign;
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (n);
}

static int	check_atoi(char *s)
{
	if (ft_strlen(s) > 11)
		return (0);
	if ((s[0] == '-' && s[1] == '0') || (s[0] == '0'
			&& (s[1] != '\0' && s[1] != ',')))
		return (0);
	return (1);
}
