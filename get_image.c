/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:40:30 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/21 16:25:21 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_hook(int keycode, t_mlx *mem);
static int	to_close(t_mlx *mem);
static void	clean_exit(t_mlx mem);

static void	fill_image(t_point **map, int **p, t_map mp, t_image image)
{
	int	i;
	int	j;

	i = 0;
	while (i < mp.height)
	{
		j = 0;
		while (j < mp.width)
		{
			if (i != mp.height -1)
				draw_line(map[i][j], map[i + 1][j], p, image);
			if (j != mp.width -1)
				draw_line(map[i][j], map[i][j + 1], p, image);
			j++;
		}
		i++;
	}
}

void	create_image(t_point **map, int wd, int ht)
{
	t_image	image;
	t_map	mp;
	t_mlx	mem;

	mp.width = wd;
	mp.height = ht;
	mem.ht = ht -1;
	mem.map = map;
	get_ready(map, &image, wd, ht);
	mem.mlx = mlx_init();
	mem.win = mlx_new_window(mem.mlx, image.width,
			image.height, "FDF - Rui Campos");
	mem.img = mlx_new_image(mem.mlx, image.width, image.height);
	mem.addr = (int *)mlx_get_data_addr(mem.img, &mem.bits_per_pixel,
			&mem.line_length, &mem.endian);
	fill_image(map, &mem.addr, mp, image);
	mlx_put_image_to_window(mem.mlx, mem.win, mem.img, 0, 0);
	mlx_key_hook(mem.win, key_hook, &mem);
	mlx_hook(mem.win, 17, 0, to_close, &mem);
	mlx_loop(mem.mlx);
}

static int	key_hook(int keycode, t_mlx *mem)
{
	if (keycode == 0xFF1B)
		clean_exit(*mem);
	return (0);
}

static int	to_close(t_mlx *mem)
{
	clean_exit(*mem);
	return (0);
}

static void	clean_exit(t_mlx mem)
{
	mlx_destroy_image(mem.mlx, mem.img);
	mlx_destroy_window(mem.mlx, mem.win);
	mlx_destroy_display(mem.mlx);
	free(mem.mlx);
	free_mem((void *)mem.map, mem.ht);
	exit(0);
}
