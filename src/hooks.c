#include "general.h"

int	exit_game(t_game *game)
{
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit(0);
	return (0);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == 53 || keysym == 65307)
		exit_game(game);
	if (keysym == 13 || keysym == 119)
		move_player(game, game->player_x, game->player_y - 1);
	if (keysym == 1 || keysym == 115)
		move_player(game, game->player_x, game->player_y + 1);
	if (keysym == 0 || keysym == 97)
		move_player(game, game->player_x - 1, game->player_y);
	if (keysym == 2 || keysym == 100)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}