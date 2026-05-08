#include "general.h"

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*img_to_draw;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			img_to_draw = game->img_floor;
			if (game->map[y][x] == '1')
				img_to_draw = game->img_wall;
			else if (game->map[y][x] == 'C')
				img_to_draw = game->img_collectible;
			else if (game->map[y][x] == 'E')
				img_to_draw = game->img_exit;
			else if (game->map[y][x] == 'P')
			{
				img_to_draw = game->img_player;
				game->player_x = x;
				game->player_y = y;
			}
			mlx_put_image_to_window(game->mlx, game->win, img_to_draw,
									x * game->tile_size, y * game->tile_size);
			x++;
		}
		y++;
	}
}