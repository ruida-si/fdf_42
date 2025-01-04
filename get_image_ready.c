/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_ready.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:40:30 by ruida-si          #+#    #+#             */
/*   Updated: 2025/01/04 19:31:52 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_hook(int keycode);

static void	fill_image(t_point **map, int **p, t_map mp, t_image image)
{
	draw_line(map[0][0], map[0][1], p, image);
	draw_line(map[0][1], map[0][2], p, image);
	draw_line(map[2][0], map[2][2], p, image);
	if (mp.width == 0)
		return ;
	/* int	i;
	int	j;

	
	
	i = 0;
	while (i < mp.height)
	{
		j = 1;
		while (j < mp.width)
		{
			map[i][j -1].x -= image.x_min;
			map[i][j -1].y -= image.y_min;
			map[i][j].x -= image.x_min;
			map[i][j].y -= image.y_min;
			
			j++;
		}
		i++;
	} */
}

void	create_image(t_point **map, int wd, int ht)
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_image	image;
	t_map	mp;

	mp.width = wd;
	mp.height = ht;
	get_ready(map, &image, wd, ht);
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "FDF - Rui Campos");
	img.img = mlx_new_image(mlx, image.width, image.height);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	fill_image(map, &img.addr, mp, image);
	mlx_put_image_to_window(mlx, win, img.img, (WIDTH - image.width) / 2,
		(HEIGHT - image.height) / 2);
	mlx_key_hook(win, key_hook, 0);
	mlx_loop(mlx);
}

static int	key_hook(int keycode)
{
	printf("Press key: %i\n", keycode);
	if (keycode == 0xFF1B)
	{
		exit(0);
	}
	return (0);
}
