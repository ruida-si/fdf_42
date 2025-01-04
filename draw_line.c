/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:14:36 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/04 19:13:58 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int n);

void	draw_line(t_point a, t_point b, int **p, t_image image)
{
	int		dx;
	int		dy;
	int		steps;
	float	x1;
	float	y1;
	int *img = *p;
	
	dx = ft_abs(b.x - a.x);
	dy = ft_abs(b.y - a.y);
	if (dx > dy)
		steps = dx;
	else
		steps = dy;
	x1 = dx / (float) steps;
	y1 = dy / (float) steps;
	int i = 0;
	float xinc = a.x;
	float yinc = a.y;
	while (i <= steps)
	{
		img[((int)yinc * image.width) + (int)xinc] = 0xFFFF00;
		xinc += x1;
		yinc += y1;
		i++;
	}
}

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}