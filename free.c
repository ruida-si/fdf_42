/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:42:24 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/27 17:14:23 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_line(char *line, char *backup, int option)
{
	if (line)
		free(line);
	if (backup)
		free(backup);
	if (option == 1)
		putstr("Map not found\n");
	if (option == 0)
		putstr("Not regular map\n");
	if (option == 3)
		exit(5);
	exit(4);
}

void	free_map(t_point **map, int y, char **av, int x)
{
	free_mem((void *)map, y);
	free_mem((void *)av, x);
}
