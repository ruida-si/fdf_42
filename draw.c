/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:37:44 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/30 20:21:38 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fdf.h"

typedef struct	s_data
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	create_window(t_point **map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 540, 300, "FDF");
	img.img = mlx_new_image(mlx, 540, 300);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);	
	for(int y = 0; y < 300; ++y)
	{
		for(int x = 0; x < 540; ++x)
		{
			int n = map[y / 30][x / 30].z;
			if (n == 10)
				color = 0xFF0000;
			else
				color = 0xFFFFFF;
			img.addr[(y * 540) + x] = color;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}