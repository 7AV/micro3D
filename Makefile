# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 13:57:34 by sbudding          #+#    #+#              #
#    Updated: 2021/01/23 15:27:20 by sbudding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

GNL = gnl.a

LIBMLX = libmlx.a

SRC = utils.c \
	parse.c \
	main.c \
	move.c \
	fov_put.c \
	player.c \
	radar.c \
	raycast.c \
	sprites.c \
	error.c

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

%.o:%.c cub3d.h
	gcc $(FLAGS) -I mlx -c $< -o $@

run: $(NAME)
	./$(NAME) maps/map.cub

scrn: $(NAME)
	./$(NAME) maps/map.cub --save

git:
	git add .
	git commit -m save

norm:
	@norminette $(SRC) cub3d.h libft/*.c libft/*.h gnl/*.c gnl/*.h 

clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./gnl
		$(MAKE) clean -C ./mlx
		rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(MAKE) clean -C ./gnl
		$(MAKE) clean -C ./mlx
		rm -rf $(NAME) libft.a gnl.a libmlx.a

re: fclean all


