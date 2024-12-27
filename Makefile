# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruida-si <ruida-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 16:39:34 by ruida-si          #+#    #+#              #
#    Updated: 2024/12/27 19:21:24 by ruida-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Werror -Wextra -Wall

SRC = fdf.c fdf_split.c fdf_get_map.c free.c fdf_utils.c

GNL = ./get_next_line/

GNL_F = $(addprefix $(GNL), get_next_line.c get_next_line_utils.c)

OBJ = $(SRC:.c=.o) $(GNL_F:.c=.o)

NAME = fdf

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(GNL_F) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
