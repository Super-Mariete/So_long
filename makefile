NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	# Configuración para Linux
	MLX_DIR = mlx_linux
	MLX = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
	INCLUDES = -I$(MLX_DIR) -I/usr/include -Iinclude -I$(LIBFT_DIR)
else
	# Configuración para macOS (Darwin)
	MLX_DIR = mlx_mac
	MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	INCLUDES = -I$(MLX_DIR) -Iinclude -I$(LIBFT_DIR)
endif

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT)
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@echo "mlx compiled"
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) $(LIBFT) $(MLX) -o $(NAME)

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
