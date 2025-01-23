# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 16:39:34 by ruida-si          #+#    #+#              #
#    Updated: 2025/01/23 13:41:03 by ruida-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Werror -Wextra -Wall -lXext -lX11 -lm -g

SRC = $(GNL_F) fdf.c split.c get_map.c free.c get_colors.c isometric.c \
	get_image.c draw_line.c

GNL = ./get_next_line/

MLX = ./minilibx-linux/

GNL_F = $(addprefix $(GNL), get_next_line.c get_next_line_utils.c)

OBJ = $(SRC:.c=.o)

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(MLX)
	$(CC) $(FLAGS) $(OBJ) $(MLX)libmlx.a -o $(NAME)

ap: mlx maps

del:
	rm -rf minilibx-linux
	rm -rf test_maps

mlx:
	wget https://cdn.intra.42.fr/document/document/27219/minilibx-linux.tgz
	tar xf minilibx-linux.tgz
	rm -rf minilibx-linux.tgz
	rm -rf minilibx-linux/.git
	
maps:
	wget https://cdn.intra.42.fr/document/document/27216/maps.zip
	unzip maps.zip
	rm -rf maps.zip
	rm -rf __MACOSX

clean:
	rm -rf $(OBJ)
	@make clean -s -C $(MLX)

fclean: clean
	rm -rf $(NAME)

re: fclean all
