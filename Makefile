# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 16:39:34 by ruida-si          #+#    #+#              #
#    Updated: 2025/01/09 18:09:59 by ruida-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Werror -Wextra -Wall -lXext -lX11 -lm -g

SRC = $(GNL_F) fdf.c split.c get_map.c free.c get_colors.c draw.c \
	get_image.c

GNL = ./get_next_line/
MLX = ./minilibx-linux/

GNL_F = $(addprefix $(GNL), get_next_line.c get_next_line_utils.c)

MLX_A = $(MLX)libmlx.a

NAME = fdf

$(MLX_A):
	@make -s -C $(MLX)

$(NAME): $(MLX_A)
	$(CC) $(FLAGS) $(SRC) $(MLX_A) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)
	@make clean -s -C $(MLX)

fclean: clean
	rm -rf $(NAME)

re: fclean all
