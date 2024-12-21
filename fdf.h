/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:57:41 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/19 15:57:43 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	red;
	int	green;
	int	blue;
}	t_point;

char	**fdf_split(char *line, int i, int j, char **av);
int		get_dimensions(char *s, int ht, int *wd);
void	get_map(t_point **map, int wd, char **av);
t_point	**get_line(char *file, int wd, int ht);
void	putstr(char *s);

#endif
