/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:32:02 by made-ped          #+#    #+#             */
/*   Updated: 2026/03/30 01:32:12 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (1);

	win = mlx_new_window(mlx, 500, 500, "42 MiniLibX");
	if (!win)
		return (1);

	mlx_loop(mlx);
	return (0);
}
