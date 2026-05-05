#include "general.h"

/**
 * Verifica que el nombre del archivo termine con la extensión correcta.
 * Para so_long se usa ".ber". Para cub3D se usa ".cub".
 */
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

/**
 * Función de ejemplo para iniciar el parseo.
 * Aquí es donde normalmente abrirías el archivo y usarías get_next_line.
 */
void	init_parse(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nNo se pudo abrir el archivo\n", 2);
		exit(1);
	}
	ft_putstr_fd("Abriendo mapa: ", 1);
	ft_putstr_fd(map_path, 1);
	ft_putstr_fd("... [OK]\n", 1);
	
	close(fd);
}

int	main(int argc, char **argv)
{
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

	init_parse(argv[1]);

	// Si el parseo es correcto, aquí iniciarías la MiniLibX
	ft_putstr_fd("Parseo inicial completado con éxito.\n", 1);

	return (0);
}