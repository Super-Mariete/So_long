#include "general.h"

int	check_extension(char *filename, char *extension)
{
	size_t	len_f;
	size_t	len_e;

	if (!filename || !extension)
		return (0);
	len_f = ft_strlen(filename);
	len_e = ft_strlen(extension);
	if (len_f <= len_e)
		return (0);
	if (ft_strncmp(filename + (len_f - len_e), extension, len_e) == 0)
		return (1);
	return (0);
}

void	free_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}