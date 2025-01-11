/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:12:23 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/11 19:41:17 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_gradient(int a, int b, float fraction);

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

int	get_gradient(int a, int b, float fraction)
{
	t_rgb	curr;
	t_rgb	next;
	int		color;

	curr.blue = a & 0xFF;
	curr.green = (a >> 8) & 0xFF;
	curr.red = (a >> 16) & 0xFF;
	next.blue = b & 0xFF;
	next.green = (b >> 8) & 0xFF;
	next.red = (b >> 16) & 0xFF;
	curr.blue = curr.blue + fraction * (next.blue - curr.blue);
	curr.green = curr.green + fraction * (next.green - curr.green);
	curr.red = curr.red + fraction * (next.red - curr.red);	
	color = (curr.red << 16) | (curr.green << 8) | curr.blue;
	return (color);	
}

/* int main()
{
	get_gradient(0xFF0000, 0x0000FF, 0.1);
	
} */
