/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:17:34 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/21 19:17:39 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_atoi(char *s, char **colors);
static int	check_atoi(char *s);
static void	get_line(t_point **map, int wd, char **av, char *line);
static void	free_exit(void **map, void **av, char *line);

int	open_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		putstr("Could not open file.\n");
		exit(2);
	}
	return (fd);
}

t_point	**get_map(char *file, int wd, int ht)
{
	int		fd;
	char	*line;
	char	**av;
	t_point	**map;

	map = malloc(sizeof(t_point *) * (ht));
	if (!map)
		exit(5);
	fd = open_file(file);
	line = get_next_line(fd);
	while (line && line[0] != '\0')
	{
		av = fdf_split(line, 0, 0, NULL);
		get_line(map, wd, av, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (map);
}

static void	get_line(t_point **map, int wd, char **av, char *line)
{
	int			z;
	int			x;
	static int	y;
	char		*colors;

	x = 0;
	map[y] = malloc(sizeof(t_point) * (wd));
	if (!map[y])
	{
		free_mem((void **)map, y -1);
		exit(5);
	}
	while (av[x])
	{
		colors = NULL;
		z = ft_atoi(av[x], &colors);
		if (z == 0 && !(av[x][0] == '0' && av[x][1] == '\0'))
			free_exit((void **)map, (void **)av, line);
		map[y][x].z = z;
		x++;
		if (y == 16 && colors)
			printf("%s\n", colors);
	}
	free_mem((void **)av, wd -1);
	y++;
	return ;
}

static void	free_exit(void **map, void **av, char *line)
{
	free_mem(av, 0);
	free_mem(map, 0);
	if (line)
		free(line);
	exit(6);
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
	if ((s[0] == '-' && s[1] == '0') || (s[0] == '0' && s[1] != '\0'))
		return (0);
	return (1);
}
