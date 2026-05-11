#include "general.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles_count++;
		ft_putstr_fd("Coleccionables: ", 1);
		ft_putnbr_fd(game->collectibles_count, 1);
		ft_putstr_fd("/", 1);
		ft_putnbr_fd(game->total_collectibles, 1);
		ft_putstr_fd("\n", 1);
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles_count == game->total_collectibles)
		{
			ft_putstr_fd("¡TE HAS COMIDO TODAS LAS MIERDAS! Fin del juego.\n", 1);
			exit_game(game);
		}
		ft_putstr_fd("Aun faltan mierdas por recoger...\n", 1);
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_y][game->player_x] = 'P';
	game->moves++;
	ft_putstr_fd("Movimientos: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
	draw_map(game);
}
