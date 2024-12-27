/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:22:27 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/27 20:00:53 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_ncolor(char **colors, int n, int i, int j);
//static int	check_hexa(char *s);

void	get_colors(t_point **map, int y, int x, char *colors)
{
	if (colors && (ft_strlen(colors) != 8))
		colors = NULL;
	if (!colors)
	{
		map[y][x].red = 255;
		map[y][x].green = 255;
		map[y][x].blue = 255;
		return ;
	}
	colors = colors + 2;
	map[y][x].red = get_ncolor(&colors, 0, 0, 0);
	map[y][x].green = get_ncolor(&colors, 0, 0, 0);
	map[y][x].blue = get_ncolor(&colors, 0, 0, 0);
}

/* static int	check_hexa(char *s)
{
	char	*hexa;
	int		i;
	int		flag;

	i = 0;
	hexa = "0123456789ABCDEF";
	while (*s)
	{
		flag = 0;
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
} */

static int	get_ncolor(char **colors, int n, int i, int j)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	while (**colors && j < 2)
	{
		i = 0;
		while (hexa[i])
		{
			if (**colors == hexa[i])
			{
				n = n * 16 + i;
				break ;
			}
			i++;
		}
		j++;
		(*colors)++;
	}
	return (n);
}

/* int main()
{
	char *colors = "FF0FAF";
	int n = get_ncolor(&colors, 0, 0, 0);
	printf("%i\n", n);
	n = get_ncolor(&colors, 0, 0, 0);
	printf("%i\n", n);
	n = get_ncolor(&colors, 0, 0, 0);
	printf("%i\n", n);
} */