NAME = so_long
CC = gcc
FLAGS = -Wall -Werror -Wextra 
MLX = libmlx.a
SRC = so_long.c ./srcs/map/map_general.c ./srcs/map/map_process.c ./srcs/window/window_process.c ./srcs/player/player_render.c
OBJ = $(SRC:.c=.o)
HEADER = 

all: $(MLX) $(NAME)

$(MLX): 
	make -C ./mlx

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c #$(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re