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
	int	z;
	int	red;
	int	green;
	int	blue;
}	t_point;

// SPLIT
char	**fdf_split(char *line, int i, int j, char **av);
void	free_mem(void **av, int i);

// GET MAP FUNCTIONS
t_point	**get_map(char *file, int wd, int ht);

// BASIC UTILS
void	putstr(char *s);
int		open_file(char *s);

#endif
