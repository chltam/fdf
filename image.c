/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:10:13 by htam              #+#    #+#             */
/*   Updated: 2023/03/17 17:38:20 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pix_to_img(t_fdf *fdf, int x, int y)
{
	int		pos;
	char	*addr;

	pos = y * fdf->size_line + x * fdf->bpp / 8;
	if (x <= 0 || y <= 0 || x >= 1920 || y >= 1080)
		return ;
	addr = fdf->data_addr + pos;
	*(unsigned int *)addr = fdf->move.color;
}

void	remake_img(t_fdf *fdf, int key)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
	put_line(fdf, fdf->move, key);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
