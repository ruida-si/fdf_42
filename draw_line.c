/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:12:23 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/21 20:02:13 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_gradient(int a, int b, int i, int steps);
static int	ft_abs(int n);

void	draw_line(t_point a, t_point b, int *img, t_image image)
{
	t_line	line;
	int		i;

	line.dx = b.x - a.x;
	line.dy = b.y - a.y;
	if (ft_abs(line.dx) > ft_abs(line.dy))
		line.steps = ft_abs(line.dx);
	else
		line.steps = ft_abs(line.dy);
	line.dx = line.dx / line.steps;
	line.dy = line.dy / line.steps;
	line.x1 = a.x;
	line.y1 = a.y;
	i = -1;
	while (++i <= line.steps)
	{
		line.y = line.y1 - image.y_min;
		line.x = line.x1 - image.x_min;
		img[(line.y * image.width) + line.x] = get_gradient(a.color,
				b.color, i, line.steps);
		line.x1 += line.dx;
		line.y1 += line.dy;
	}
}

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static int	get_gradient(int a, int b, int i, int steps)
{
	t_rgb	curr;
	t_rgb	next;
	int		color;
	float	fraction;

	fraction = i / (float) steps;
	curr.blue = a & 0xFF;
	curr.green = (a >> 8) & 0xFF;
	curr.red = (a >> 16) & 0xFF;
	next.blue = b & 0xFF;
	next.green = (b >> 8) & 0xFF;
	next.red = (b >> 16) & 0xFF;
	curr.blue = curr.blue + (fraction * (next.blue - curr.blue));
	curr.green = curr.green + (fraction * (next.green - curr.green));
	curr.red = curr.red + (fraction * (next.red - curr.red));
	color = (curr.red << 16) | (curr.green << 8) | curr.blue;
	return (color);
}
