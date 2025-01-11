/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:37:44 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/11 18:12:10 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		isometric(t_point **map, int i, int j);
static t_point	**copy(t_point **map, int wd, int ht);

static void	get_2d(t_point **map, int wd, int ht, int zoom)
{
	int	i;
	int	j;

	i = 0;
	while (i < ht)
	{
		j = 0;
		while (j < wd)
		{
			map[i][j].x *= zoom;
			map[i][j].y *= zoom;
			map[i][j].z *= zoom;
			isometric(map, i, j);
			j++;
		}
		i++;
	}
}

static void	isometric(t_point **map, int i, int j)
{
	int	temp;
	int	x;
	int	y;

	temp = map[i][j].x;
	x = (temp - map[i][j].y) * cos(0.523599);
	y = (temp + map[i][j].y) * sin(0.523599) - map[i][j].z;
	map[i][j].x = x;
	map[i][j].y = y;
	map[i][j].z = 0;
}

static void	get_dimensions2(t_point **map, int wd, int ht, t_image *image)
{
	int	i;
	int	j;

	image->x_max = map[0][0].x;
	image->y_max = map[0][0].y;
	image->x_min = image->x_max;
	image->y_min = image->y_max;
	i = 0;
	while (i < ht)
	{
		j = 0;
		while (j < wd)
		{
			if (map[i][j].x > image->x_max)
				image->x_max = map[i][j].x;
			if (map[i][j].y > image->y_max)
				image->y_max = map[i][j].y;
			if (map[i][j].x < image->x_min)
				image->x_min = map[i][j].x;
			if (map[i][j].y < image->y_min)
				image->y_min = map[i][j].y;
			j++;
		}
		i++;
	}
}

void	get_ready(t_point **map, t_image *image, int wd, int ht)
{
	int		zoom;
	t_point	**map2;

	zoom = 1;
	while (zoom > 0)
	{
		map2 = copy(map, wd, ht);
		get_2d(map2, wd, ht, zoom);
		get_dimensions2(map2, wd, ht, image);
		free_mem((void *)map2, ht -1);
		image->width = image->x_max - image->x_min + 1;
		image->height = image->y_max - image->y_min + 1;
		if (image->width > 1920 || image->height > 1000 || zoom > 20)
			break ;
		zoom++;
	}
	zoom--;
	get_2d(map, wd, ht, zoom);
	get_dimensions2(map, wd, ht, image);
	image->width = image->x_max - image->x_min + 1;
	image->height = image->y_max - image->y_min + 1;
}

static t_point	**copy(t_point **map, int wd, int ht)
{
	t_point	**map2;
	int		i;
	int		j;

	map2 = malloc(sizeof(t_point *) * (ht));
	i = 0;
	while (i < ht)
	{
		map2[i] = malloc(sizeof(t_point) * wd);
		j = 0;
		while (j < wd)
		{
			map2[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (map2);
}
