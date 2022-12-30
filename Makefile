NAME = so_long
MLX = ./MLX42/libmlx42.a
LIBFT = ./libft/libft.a

HEADER = so_long.h

SRCS = main.c srcs/checks/convert.c srcs/checks/errors.c srcs/checks/file.c \
		srcs/checks/map.c srcs/checks/path.c srcs/checks/utils.c srcs/so_long.c \
		srcs/mlx/keys.c srcs/mlx/player_render.c srcs/mlx/tiles.c srcs/mlx/utils.c

CC = gcc
FLAGS = -Wall -Werror -Wextra # -g -fsanitize=address

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) -o $@ $(SRCS) $(MLX) $(LIBFT) $(MLX) -lglfw

$(MLX):
	make -C ./MLX42

$(LIBFT):
	make -C ./libft

clean:
	make clean -C ./MLX42
	make clean -C ./libft

fclean: clean
	rm -f $(MLX)
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re