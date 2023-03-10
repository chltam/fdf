/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:10:13 by htam              #+#    #+#             */
/*   Updated: 2023/03/10 16:50:02 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    put_pix_to_img(t_fdf *fdf, int x, int y)
{
    int	pos;
	char	*addr;
	unsigned int	color;

	color = 0xFFFFFFFF;
	pos = y * fdf->size_line + x * fdf->bpp / 8;

	if (x <= 0 || y <= 0 || x >= 1920 || y >= 1080)
		return ;
	addr = fdf->data_addr + pos;
	*(unsigned int *)addr = 0xFFFFFFFF;

}