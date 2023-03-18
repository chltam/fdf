/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:41:30 by htam              #+#    #+#             */
/*   Updated: 2023/03/18 16:34:48 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(char ***map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			free(map[y][x]);
			x++;
		}
		free(map[y]);
		y++;
	}
	free(map);
}

void	free_all(t_fdf *fdf)
{
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->win)
		mlx_clear_window(fdf->mlx, fdf->win);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	if (fdf->map)
		free_map(fdf->map);
	if (fdf)
		free(fdf);
}

int	free_and_exit(t_fdf *fdf)
{
	free_all(fdf);
	exit(0);
	return (0);
}
