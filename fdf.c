/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:57:26 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/19 15:57:29 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_fdf(char *s);
static int	check_input(char *s, int ac);

int	main(int ac, char **av)
{
	int		wd;
	int		ht;
	t_point	**map;
	
	wd = 0;
	if (!check_input(av[1], ac))
		return (1);
	ht = get_dimensions(av[1], 0, &wd);
	if (ht == 0)
		return (1);
	map = get_line(av[1], wd, ht);
	printf("%i\n", map[2][1].z);
	return (0);
}

void	putstr(char *s)
{
	int	i;

	if (!s)
		s = "(null)\n";
	i = ft_strlen(s);
	write(2, s, i);
}

static int	check_input(char *s, int ac)
{
	if (ac != 2)
	{
		putstr("Error: Not 1 argument.\n");
		return (0);
	}
	if (ft_strlen(s) < 5 || !check_fdf(s))
	{
		putstr("Error: Not a .fdf file.\n");
		return (0);
	}
	return (1);
}

static int	check_fdf(char *s)
{
	int		i;
	char	*file;

	file = ".fdf";
	i = ft_strlen(s) - 4;
	while (s[i])
	{
		if (s[i++] != *file++)
			return (0);
	}
	return (1);
}
