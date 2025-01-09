/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:37:44 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/09 18:06:18 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(t_point **map, int i, int j);

void	draw_line(t_point a, t_point b, int **p, t_image image)
{
	int		*img;
	t_line	line;
	int		i;

	img = *p;
	line.dx = b.x - a.x;
	line.dy = b.y - a.y;
	if (line.dx > line.dy)
		line.steps = line.dx;
	else
		line.steps = line.dy;
	line.dx = line.dx / line.steps;
	line.dy = line.dy / line.steps;
	line.x1 = a.x;
	line.y1 = a.y;
	i = 0;
	while (i <= line.steps)
	{
		line.y = line.y1 - image.y_min;
		line.x = line.x1 - image.x_min;
		img[(line.y * image.width) + line.x] = a.color;
		line.x1 += line.dx;
		line.y1 += line.dy;
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

	if (wd < 50 && ht < 50)
		zoom = 20;
	else
		zoom = 1;
	get_2d(map, wd, ht, zoom);
	get_dimensions2(map, wd, ht, image);
	image->width = image->x_max - image->x_min + 1;
	image->height = image->y_max - image->y_min + 1;
}
