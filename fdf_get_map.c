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

static int	ft_atoi(char *s);

int	open_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		putstr("Could not open file.\n");
		return (-1);
	}
	return (fd);
}

int	get_dimensions(char *s, int ht, int *wd)
{
	int		fd;
	char	*line;

	fd = open_file(s);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	*wd = count_wd(line);
	while (line && line[0] != '\0')
	{
		ht++;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (ht);
}

t_point	**get_line(char *file, int wd, int ht)
{
	int		fd;
	char	*line;
	char	**av;
	t_point	**map;

	map = malloc(sizeof(t_point *) * (ht));
	fd = open_file(file);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line && line[0] != '\0')
	{
		av = fdf_split(line, 0, 0, NULL);
		get_map(map, wd, av);
		free(line);
		line = NULL;		
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (map);
}

void	get_map(t_point **map, int wd, char **av)
{
	int			z;
	int			x;
	static int	y;

	x = 0;	
	map[y] = malloc(sizeof(t_point) * (wd));
	while (av[x])
	{		
		z = ft_atoi(av[x]);
		map[y][x].x = x;
		map[y][x].y = y;
		map[y][x].z = z;
		x++;
	}
	return ;
}

static int	ft_atoi(char *s)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (ft_strlen(s) > 11)
		return (0);
	if ((s[0] == '-' && s[1] == '0') || (s[0] == '0' && s[1] != '\0'))
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
	n *= sign;
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (n);
}
