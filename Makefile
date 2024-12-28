# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruida-si <ruida-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 16:39:34 by ruida-si          #+#    #+#              #
#    Updated: 2024/12/28 19:28:24 by ruida-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Werror -Wextra -Wall -lXext -lX11

SRC = fdf.c split.c get_map.c free.c get_colors.c

GNL = ./get_next_line/

MLX = ./minilibx-linux/

MLX_A = $(addprefix $(MLX), libmlx.a)

GNL_F = $(addprefix $(GNL), get_next_line.c get_next_line_utils.c)

OBJ = $(SRC:.c=.o) $(GNL_F:.c=.o)

NAME = fdf

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(GNL_F) -o $(NAME)

all: $(NAME)

$(MLX_A):
	@$(MAKE) -s -C $(MLX)
	
ap: $(MLX_A)
	$(CC) $(FLAGS) draw.c $(MLX)libmlx.a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
