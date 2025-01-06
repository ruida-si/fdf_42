/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:37:44 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/06 19:33:24 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	isometric(int x, int y, int z);

void	draw_line(t_point a, t_point b, int **p, t_image image)
{
	int		dx;
	int		dy;
	int		steps;
	int *img = *p;
	
	dx = b.x - a.x;
	dy = b.y - a.y;
	if (dx > dy)
		steps = dx;
	else
		steps = dy;
	float xinc = dx / (float) steps;
	float yinc = dy / (float) steps;
	float x1 = a.x;
	float y1 = a.y;
	int i = 0;
	while (i <= steps)
	{
		int y = y1 - image.y_min;
		int x = x1 - image.x_min;
		img[(y * image.width) + x] = 0x00FF00;
		x1 += xinc;
		y1 += yinc;
		i++;
	}
}

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
			map[i][j] = isometric(map[i][j].x, map[i][j].y, map[i][j].z);
			j++;
		}
		i++;
	}
}

static t_point	isometric(int x, int y, int z)
{
	int		temp;
	t_point	map;

	temp = x;
	x = (temp - y) * cos(0.523599);
	y = (temp + y) * sin(0.523599) - z;
	map.x = x;
	map.y = y;
	map.z = 0;
	return (map);
}

static void	get_dimensions(t_point **map, int wd, int ht, t_image *image)
{
	int		i;
	int		j;

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
	int	zoom;
	
	zoom = 20;
	get_2d(map, wd, ht, zoom);
	get_dimensions(map, wd, ht, image);
	image->width = image->x_max - image->x_min + 1;
	image->height = image->y_max - image->y_min + 1;
}
