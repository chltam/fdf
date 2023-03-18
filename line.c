/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:37:23 by htam              #+#    #+#             */
/*   Updated: 2023/03/18 16:26:16 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Bresenham's line algorithm*/

int	get_one(int n0, int n1)
{
	if (n0 < n1)
		return (1);
	return (-1);
}

void	draw_line(t_iso iso0, t_iso iso1, t_fdf *fdf)
{
	int	dx;
	int	dy;
	int	err;
	int	e2;

	dx = abs((int)iso1.x - (int)iso0.x);
	dy = abs((int)iso1.y - (int)iso0.y);
	err = dx - dy;
	while (iso0.x != iso1.x || iso0.y != iso1.y)
	{
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			iso0.x += get_one(iso0.x, iso1.x);
		}
		if (e2 < dx)
		{
			err += dx;
			iso0.y += get_one(iso0.y, iso1.y);
		}
		put_pix_to_img(fdf, iso0.x, iso0.y);
	}
}

void	read_z_draw(int x, int y, t_fdf *fdf)
{
	t_iso	iso;
	t_iso	last_x;
	t_iso	last_y;

	iso = iso_rotate(make_cart(x, y, ft_atoi(fdf->map[y][x])), fdf->move);
	iso = transform_iso(iso, fdf->move);
	if (x > 0)
	{
		last_x = iso_rotate(make_cart(x - 1, y, ft_atoi(fdf->map[y][x - 1])),
				fdf->move);
		last_x = transform_iso(last_x, fdf->move);
		draw_line(iso, last_x, fdf);
	}
	if (y > 0)
	{
		last_y = iso_rotate(make_cart(x, y - 1, ft_atoi(fdf->map[y - 1][x])),
				fdf->move);
		last_y = transform_iso(last_y, fdf->move);
		draw_line(iso, last_y, fdf);
	}
}

void	put_line(t_fdf *fdf, t_move move, int key)
{
	int		y;
	int		x;

	y = 0;
	while (fdf->map[y])
	{
		x = 0;
		while (fdf->map[y][x])
		{
			read_z_draw(x, y, fdf);
			x++;
		}
		y++;
	}
}
