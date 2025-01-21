/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:17:34 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/21 17:14:15 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_atoi(char *s, char **colors);
static int	check_atoi(char *s);
static int	get_line(t_point **map, int wd, char **av, int x);
static int	init_map(t_point **map, int wd, char **av, int y);

t_point	**get_map(char *file, int wd, int ht)
{
	int			fd;
	char		*line;
	static char	*backup;
	char		**av;
	t_point		**map;

	map = malloc(sizeof(t_point *) * (ht));
	if (!map)
		exit(7);
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

	if (!init_map(map, wd, av, y))
		return (0);
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
		map[y][x].y = wd -1 - x;
		map[y][x].x = y;
		get_colors(map, y, x, colors);
		x++;
	}
	free_mem((void **)av, wd -1);
	y++;
	return (1);
}

static int	init_map(t_point **map, int wd, char **av, int y)
{
	map[y] = malloc(sizeof(t_point) * (wd));
	if (!map[y])
	{
		free_map(map, y -1, av, wd -1);
		return (0);typedef struct s_line
{
	float	dx;
	float	dy;
	int		steps;
	float	x1;
	float	y1;
	int		x;
	int		y;
}	t_line;
	}
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
	if (ft_strlen(s) > 20)
		return (0);
	if ((s[0] == '-' && s[1] == '0') || (s[0] == '0'
			&& (s[1] != '\0' && s[1] != ',')))
		return (0);
	return (1);
}
