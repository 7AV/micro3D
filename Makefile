NAME = micro3D

FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

GNL = gnl.a

LIBMLX = libmlx.a

SRC = src/main.c \
	src/input.c \
	src/parse.c \
	src/checkup.c \
	src/player.c \
	src/radar.c \
	src/move.c \
	src/render.c \
	src/raycast.c \
	src/sprites.c \
	src/errors.c \
	src/screenshot.c \
	src/service.c \
	src/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GNL) $(LIBMLX) src/micro3d.h
	@gcc libft.a gnl.a libmlx.a -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)
	@echo "\033[0;32mSuccess: micro3D instaled!\033[0m"

$(LIBFT):
	@$(MAKE) bonus -C ./src/libft
	@cp src/libft/libft.a .

$(GNL):
	@$(MAKE) -C ./src/gnl
	@cp src/gnl/gnl.a .

$(LIBMLX):
	@$(MAKE) -C ./src/mlx
	@cp src/mlx/libmlx.a .

%.o:%.c src/micro3d.h
	@gcc $(FLAGS) -I mlx -c $< -o $@

run: $(NAME)
	./$(NAME) map/default.cub

scrn: $(NAME)
	./$(NAME) map/default.cub --save

clean:
	@$(MAKE) clean -C ./src/libft
	@$(MAKE) clean -C ./src/gnl
	@$(MAKE) clean -C ./src/mlx
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C ./src/libft
	@$(MAKE) clean -C ./src/gnl
	@$(MAKE) clean -C ./src/mlx
	@rm -rf $(NAME) libft.a gnl.a libmlx.a

re: fclean all



