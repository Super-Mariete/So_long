NAME = mlx_test

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c

MLX_DIR = mlx
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

INCLUDES = -Imlx

all: $(NAME)

$(NAME):
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) $(MLX) -o $(NAME)

clean:
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
