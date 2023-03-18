/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:12:40 by htam              #+#    #+#             */
/*   Updated: 2023/03/17 23:37:40 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	wasdqe_hook(int key, t_fdf *fdf)
{
	if (key == W_KEY)
		fdf->move.rotate_y--;
	if (key == S_KEY)
		fdf->move.rotate_y++;
	if (key == A_KEY)
		fdf->move.rotate_x--;
	if (key == D_KEY)
		fdf->move.rotate_x++;
	if (key == Q_KEY)
		fdf->move.rotate_z++;
	if (key == E_KEY)
		fdf->move.rotate_z--;
	if (fdf->move.rotate_x == 360 || fdf->move.rotate_x == -360)
		fdf->move.rotate_x = 0;
	if (fdf->move.rotate_y == 360 || fdf->move.rotate_y == -360)
		fdf->move.rotate_y = 0;
	if (fdf->move.rotate_z == 360 || fdf->move.rotate_z == -360)
		fdf->move.rotate_z = 0;
	remake_img(fdf, key);
}

void	udlr_hook(int key, t_fdf *fdf)
{
	if (key == UP)
		fdf->move.offset_y -= 10;
	if (key == DOWN)
		fdf->move.offset_y += 10;
	if (key == LEFT)
		fdf->move.offset_x -= 10;
	if (key == RIGHT)
		fdf->move.offset_x += 10;
	remake_img(fdf, key);
}

void	pm_hook(int key, t_fdf *fdf)
{
	if (key == PLUS)
		fdf->move.zoom++;
	if (key == MINUS)
		fdf->move.zoom--;
	remake_img(fdf, key);
}

void	rgb_hook(int key, t_fdf *fdf)
{
	if (key == R_KEY)
		fdf->move.color = 0x00FF0000;
	if (key == G_KEY)
		fdf->move.color = 0x0000FF00;
	if (key == B_KEY)
		fdf->move.color = 0x000000FF;
	if (key == Y_KEY)
		fdf->move.color = 0x00FFFF00;
	remake_img(fdf, key);
}
