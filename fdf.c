/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:24:54 by htam              #+#    #+#             */
/*   Updated: 2023/03/18 17:06:12 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	rad(double deg)
{
	double	rad;

	rad = deg * M_PI / 180;
	return (rad);
}

void	check_map(t_fdf *fdf)
{
	int	y;
	int	first_x;
	int	x;

	y = 0;
	first_x = 0;
	while (fdf->map[y])
	{
		while (y == 0 && fdf->map[y][first_x])
			first_x++;
		x = 0;
		while (y > 0 && fdf->map[y][x])
		{
			x++;
		}
		if (y > 0 && x != first_x)
		{
			ft_printf("Map Error\n");
			free_and_exit(fdf);
		}
		y++;
	}
}

int	fdf_key_hook(int key, t_fdf *fdf)
{
	if (key == ESC)
		free_and_exit(fdf);
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY
		|| key == Q_KEY || key == E_KEY)
		wasdqe_hook(key, fdf);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		udlr_hook(key, fdf);
	if (key == PLUS || key == MINUS)
		pm_hook(key, fdf);
	if (key == R_KEY || key == G_KEY || key == B_KEY || key == Y_KEY)
		rgb_hook(key, fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (0);
	fdf = init_fdf(argv[1]);
	if (!fdf)
		return (0);
	check_map(fdf);
	put_line(fdf, fdf->move, 1);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_hook(fdf->win, KeyPress, KeyPressMask, fdf_key_hook, fdf);
	mlx_hook(fdf->win, DestroyNotify, StructureNotifyMask, free_and_exit, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
