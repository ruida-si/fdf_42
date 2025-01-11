/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:57:26 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/10 15:09:23 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_fdf(char *s);
static int	check_input(char *s, int ac);
static int	get_dimensions(char *s, int ht, int *wd, int fd);

int	main(int ac, char **av)
{
	int		wd;
	int		ht;
	t_point	**map;

	wd = 0;
	check_input(av[1], ac);
	ht = get_dimensions(av[1], 0, &wd, 0);
	map = get_map(av[1], wd, ht);
	create_image(map, wd, ht);
	return (0);
}

static int	get_dimensions(char *s, int ht, int *wd, int fd)
{
	char		*line;
	static char	*backup;

	fd = open_file(s);
	line = get_next_line(fd, &backup);
	*wd = count_wd(line);
	if (*wd == 0)
		free_line(line, backup, 1);
	while (line && line[0] != '\0')
	{
		ht++;
		if (count_wd(line) > *wd)
			*wd = count_wd(line);
		free(line);
		line = get_next_line(fd, &backup);
	}
	if (line)
		free(line);
	close(fd);
	return (ht);
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
	if (ac != 2 || ft_strlen(s) < 5 || !check_fdf(s))
	{
		putstr("Error >> Usage: ./fdf file.fdf\n");
		exit(1);
	}
	return (1);
}

static int	check_fdf(char *s)
{
	int		i;
	char	*file;

	file = ".fdf";
	i = ft_strlen(s) - 4;
	if (s[i -1] == '/')
		return (0);
	while (s[i])
	{
		if (s[i++] != *file++)
			return (0);
	}
	return (1);
}
