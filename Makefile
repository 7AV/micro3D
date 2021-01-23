# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 13:57:34 by sbudding          #+#    #+#              #
#    Updated: 2021/01/23 10:49:48 by sbudding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

GNL = gnl.a

LIBMLX = libmlx.a

SRC = img_build.c \
	input_parse.c \
	main.c \
	player_move.c \
	fov_put.c \
	player_set.c \
	radar.c \
	ray_cast.c \
	sprites_put.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GNL) $(LIBMLX) cub3d.h
	gcc libft.a gnl.a libmlx.a -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft
	cp libft/libft.a .

$(GNL):
	$(MAKE) -C ./gnl
	cp gnl/gnl.a .

$(LIBMLX):
	$(MAKE) -C ./mlx
	cp mlx/libmlx.a .

run: $(NAME)
	./$(NAME) map.cub

clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./gnl
		$(MAKE) clean -C ./mlx
		rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(MAKE) clean -C ./gnl
		$(MAKE) clean -C ./mlx
		rm -rf libft.a
		rm -rf gnl.a
		rm -rf libmlx.a
		rm -rf $(NAME)
		rm -rf a.out

re: fclean all

.PHONY: bonus clean fclean all refov_put.c

