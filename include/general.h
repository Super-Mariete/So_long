#ifndef GENERAL_H
# define GENERAL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"

/* Prototipos de funciones */
int		check_extension(char *filename, char *extension);
void	init_parse(char *map_path);

#endif