#ifndef GENERAL_H
# define GENERAL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map; // El mapa como una matriz de caracteres
	int		map_width; // Ancho del mapa en tiles
	int		map_height; // Alto del mapa en tiles
	int		tile_size; // Tamaño de cada tile en píxeles

	// Punteros a las imágenes (texturas)
	void	*img_player;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	void	*img_floor;

	int		player_x; // Posición X del jugador en tiles
	int		player_y; // Posición Y del jugador en tiles

	int		collectibles_count;
	int		total_collectibles;
	int		moves;
}	t_game;

/* Prototipos de funciones */
int		check_extension(char *filename, char *extension);
void	init_parse(char *map_path, t_game *game);
int		exit_game(t_game *game);
void	load_textures(t_game *game);
void	draw_map(t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
int		handle_keypress(int keysym, t_game *game);
void	free_map(t_game *game);

#endif