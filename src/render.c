#include "general.h"

void	draw_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			// 1. Siempre dibujamos el suelo primero si no es una pared
			if (game->map[y][x] != '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
					x * game->tile_size, y * game->tile_size);

			// 2. Dibujamos el elemento correspondiente encima
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
					x * game->tile_size, y * game->tile_size);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collectible,
					x * game->tile_size, y * game->tile_size);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
					x * game->tile_size, y * game->tile_size);
			else if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
					x * game->tile_size, y * game->tile_size);
			}
			x++;
		}
		y++;
	}
}