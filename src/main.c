#include "general.h"

int	main(int argc, char **argv)
{
	t_game	game;

	// Inicializar la estructura del juego a 0 para evitar valores basura
	ft_bzero(&game, sizeof(t_game));

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUso: ./so_long [mapa.ber]\n", 2);
		return (1);
	}

	// Validamos la extensión del archivo
	if (!check_extension(argv[1], ".ber"))
	{
		ft_putstr_fd("Error\nEl archivo debe tener extensión .ber\n", 2);
		return (1);
	}

	// Pasar la dirección de 'game' a init_parse para que pueda modificarla
	init_parse(argv[1], &game);

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	
	game.tile_size = 64;
	// Crear la ventana con el tamaño del mapa * tamaño del tile
	game.win = mlx_new_window(game.mlx, game.map_width * game.tile_size,
								game.map_height * game.tile_size, "so_long - 42");
	if (!game.win)
		return (1);
	
	load_textures(&game); // Cargar todas las imágenes
	draw_map(&game);      // Dibujar el mapa inicial

	// Hook para la X de la ventana (evento 17: DestroyNotify)
	mlx_hook(game.win, 17, 0, exit_game, &game);
	// Hook para el teclado
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}