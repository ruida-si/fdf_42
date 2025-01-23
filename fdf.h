/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:57:41 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/21 20:03:12 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>

typedef struct s_line
{
	float	dx;
	float	dy;
	int		steps;
	float	x1;
	float	y1;
	int		x;
	int		y;
}	t_line;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_point	**map;
	int		ht;
}	t_mlx;

typedef struct s_image
{
	int	x_min;
	int	y_min;
	int	x_max;
	int	y_max;
	int	width;
	int	height;
}	t_image;

typedef struct s_map
{
	int	width;
	int	height;
}	t_map;

// GENERATE IMAGE
void	get_ready(t_point **map, t_image *image, int wd, int ht);
void	draw_line(t_point a, t_point b, int *img, t_image image);
void	create_image(t_point **map, int wd, int ht);

// SPLIT
char	**fdf_split(char *line, int i, int j, char **av);
void	free_mem(void **av, int i);

// FREE MEMORY
void	free_line(char *line, char *backup, int option);
void	free_map(t_point **map, int y, char **av, int x);

// GET MAP FUNCTIONS
t_point	**get_map(char *file, int wd, int ht);
void	get_colors(t_point **map, int y, int x, char *colors);

// BASIC UTILS
void	putstr(char *s);
int		open_file(char *s);

#endif
