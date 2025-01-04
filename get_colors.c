/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:22:27 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/04 13:22:50 by ruida-si         ###   ########.fr       */
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
	if (colors && (ft_strlen(colors) != 8 || !check_hexa(colors + 2)))
		colors = NULL;
	if (!colors)
	{
		map[y][x].color = 0xFF0000;
		return ;
	}
	colors = colors + 2;
	map[y][x].color = get_ncolor(colors);
}

static int	get_ncolor(char *s)
{
	int		i;
	char	*hexa;
	int		color;

	color = 0;
	hexa = "0123456789ABCDEF";
	while (*s)
	{
		i = 0;
		while (hexa[i])
		{
			if (*s == hexa[i])
			{
				color = color * 16 + i;
				break ;
			}
			i++;
		}
		s++;
	}
	return (color);
}

static int	check_hexa(char *s)
{
	char	*hexa;
	int		i;
	int		flag;

	hexa = "0123456789ABCDEF";
	while (*s)
	{
		flag = 0;
		i = 0;
		while (hexa[i])
		{
			if (*s == hexa[i])
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
