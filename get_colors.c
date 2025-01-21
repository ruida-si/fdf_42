/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:22:27 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/21 17:10:30 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_hexa(char *s);
static int	get_ncolor(char *s);

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

void	get_colors(t_point **map, int y, int x, char *colors)
{
	t_rgb	rgb;

	rgb.red = 0;
	rgb.green = 0;
	rgb.blue = 0;
	if (!colors || ft_strlen(colors) > 8 || !check_hexa(colors + 2))
	{
		map[y][x].color = 0xFFFFFF;
		return ;
	}
	colors = colors + 2;
	if (ft_strlen(colors) == 2)
		rgb.blue = get_ncolor(colors);
	if (ft_strlen(colors) == 4)
	{
		rgb.green = get_ncolor(colors);
		rgb.blue = get_ncolor(colors + 2);
	}
	if (ft_strlen(colors) == 6)
	{
		rgb.red = get_ncolor(colors);
		rgb.green = get_ncolor(colors + 2);
		rgb.blue = get_ncolor(colors + 4);
	}
	map[y][x].color = (rgb.red << 16) | (rgb.green << 8) | rgb.blue;
}

static int	get_ncolor(char *s)
{
	int		i;
	int		j;
	char	*hexa;
	char	*hexa2;
	int		color;

	color = 0;
	hexa = "0123456789ABCDEF";
	hexa2 = "0123456789abcdef";
	j = 0;
	while (s[j] && j < 2)
	{
		i = 0;
		while (hexa[i])
		{
			if (s[j] == hexa[i] || s[j] == hexa2[i])
			{
				color = color * 16 + i;
				break ;
			}
			i++;
		}
		j++;
	}
	return (color);
}

static int	check_hexa(char *s)typedef struct s_line
{
	float	dx;
	float	dy;
	int		steps;
	float	x1;
	float	y1;
	int		x;
	int		y;
}	t_line;
{
	char	*hexa;
	char	*hexa2;
	int		i;
	int		flag;

	hexa = "0123456789ABCDEF";
	hexa2 = "0123456789abcdef";
	while (*s)
	{
		flag = 0;
		i = 0;
		while (hexa[i])
		{
			if (*s == hexa[i] || *s == hexa2[i])
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (!flag)
			return (0);
		s++;
	}
	return (1);
}
