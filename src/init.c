#include "general.h"

void	init_parse(char *map_path, t_game *game)
{
	int		fd;
	int		i;
	int		j;
	char	buffer[100000];
	int		bytes;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nNo se pudo abrir el archivo\n", 2);
		exit(1);
	}
	bytes = read(fd, buffer, 99999);
	if (bytes <= 0)
	{
		ft_putstr_fd("Error\nArchivo vacío o error de lectura\n", 2);
		close(fd);
		exit(1);
	}
	buffer[bytes] = '\0';
	game->map = ft_split(buffer, '\n');
	if (!game->map)
		exit(1);
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	if (game->map_height > 0)
		game->map_width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->total_collectibles++;
			j++;
		}
		i++;
	}
	ft_putstr_fd("Mapa cargado y parseado: ", 1);
	ft_putstr_fd(map_path, 1);
	ft_putstr_fd("... [OK]\n", 1);
	close(fd);
}

void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/pared.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "assets/collective.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/salida.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &w, &h);
	if (!game->img_player || !game->img_wall || !game->img_collectible ||
		!game->img_exit || !game->img_floor)
	{
		if (!game->img_player)
			ft_putstr_fd("Failed to load assets/player.xpm\n", 2);
		if (!game->img_wall)
			ft_putstr_fd("Failed to load assets/pared.xpm\n", 2);
		if (!game->img_collectible)
			ft_putstr_fd("Failed to load assets/collective.xpm\n", 2);
		if (!game->img_exit)
			ft_putstr_fd("Failed to load assets/salida.xpm\n", 2);
		if (!game->img_floor)
			ft_putstr_fd("Failed to load assets/floor.xpm\n", 2);
		ft_putstr_fd("Error\nNo se pudieron cargar todas las texturas.\n", 2);
		exit_game(game);
	}
}