/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:24:54 by htam              #+#    #+#             */
/*   Updated: 2023/03/10 17:05:01 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// #include <stdio.h>
/*esc = 65307*/

double	rad(double deg)
{
	double	rad;
	rad = deg * M_PI / 180;
	return (rad);
}

void draw_line(int x0, int y0, int x1, int y1, t_fdf *fdf) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
	

    while (x0 != x1 || y0 != y1)
	{
        // Draw the point at (x0, y0)
        // printf("(%d, %d)\n", x0, y0);

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
		put_pix_to_img(fdf, x0, y0);
    }
}

t_iso	cart_to_iso(int x, int y, int z)
{
	t_iso	iso;
	
	iso.x = (x - y) * cos(rad(30));
	iso.y = (x + y) * sin(rad(30)) - z;
	return (iso);
}

t_iso	iso_rotate(double x, double y, int n)
{
	t_iso	iso;
	iso.x = cos(rad(n)) * x - sin(rad(n)) * y;
	iso.y = sin(rad(n)) * x + cos(rad(n)) * y;
	return (iso);
}

t_iso	iso_rotate_vertical(double x, double y, double z, int m)
{
	// x'' = x * cos(b) + z * sin(b)
	// z'' = -x * sin(b) + z * cos(b)

	double	temp_x;
	double	temp_z;
	t_iso	iso;

	temp_x = x * cos(rad(m)) + z * sin(rad(m));
	temp_z = -x * sin(rad(m)) + z * cos(rad(m));
	iso.x = (temp_x - y) * cos(rad(30));
	iso.y = (temp_x + y) * sin(rad(30)) - temp_z;
	return (iso);

}

void	put_line(t_fdf *fdf, int n, int m, int zoom)
{
	int	y;
	int	x;
	t_iso	last_x;
	t_iso	last_y;
	t_iso	iso;

	y = 0;
	while (fdf->map[y])
	{
		x = 0;
		while (fdf->map[y][x])
		{
			// iso = cart_to_iso(x, y, ft_atoi(fdf->map[y][x]));
			iso = iso_rotate_vertical(x, y, ft_atoi(fdf->map[y][x]), m);
			iso = iso_rotate(iso.x, iso.y, n);
			// put_pix_to_img(fdf, ORIGIN_X + iso.x * 32, ORIGIN_Y + iso.y * 32);
			// printf("isox = %d\n isoy = %d\n", iso.x, iso.y);
			if (x > 0)
			{

				// last_x = cart_to_iso(x - 1, y, ft_atoi(fdf->map[y][x - 1]));
				last_x = iso_rotate_vertical(x - 1, y, ft_atoi(fdf->map[y][x - 1]), m);
				last_x = iso_rotate(last_x.x, last_x.y, n);
				draw_line(ORIGIN_X + last_x.x * zoom, ORIGIN_Y + last_x.y * zoom, ORIGIN_X + iso.x * zoom, ORIGIN_Y + iso.y * zoom, fdf);

			}
			if (y > 0)
			{
				// last_y = cart_to_iso(x, y - 1, ft_atoi(fdf->map[y - 1][x]));
				last_y = iso_rotate_vertical(x, y - 1, ft_atoi(fdf->map[y - 1][x]), m);
				last_y = iso_rotate(last_y.x, last_y.y, n);
				draw_line(ORIGIN_X + last_y.x * zoom, ORIGIN_Y + last_y.y * zoom, ORIGIN_X + iso.x * zoom, ORIGIN_Y + iso.y * zoom, fdf);
			}
			x++;
		}
		y++;
	}
}

// void	put_line(t_fdf *fdf)
// {
// 	int	y;
// 	int	x;
// 	int	pix = 8;

// 	y = 0;
// 	while (fdf->map[y])
// 	{
// 		x = 0;
// 		while (fdf->map[y][x])
// 		{
// 			// put_pix_to_img(fdf, ORIGIN_X + (x - y) * cos(rad(30)) * 32, ORIGIN_Y + ((x + y) * sin(rad(30)) - ft_atoi(fdf->map[y][x])) * 32);
// 			if (x > 0)
// 				draw_line(ORIGIN_X + (x - 1 - y) * cos(rad(30)) * pix, ORIGIN_Y + ((x - 1 + y) * sin(rad(30)) - ft_atoi(fdf->map[y][x - 1])) * pix, ORIGIN_X + (x - y) * cos(rad(30)) * pix, ORIGIN_Y + ((x + y) * sin(rad(30)) - ft_atoi(fdf->map[y][x])) * pix, fdf);
// 			if (y > 0)
// 			{
// 				draw_line(ORIGIN_X + (x - y + 1) * cos(rad(30)) * pix, ORIGIN_Y + ((x + y - 1) * sin(rad(30)) - ft_atoi(fdf->map[y - 1][x])) * pix, ORIGIN_X + (x - y) * cos(rad(30)) * pix, ORIGIN_Y + ((x + y) * sin(rad(30)) - ft_atoi(fdf->map[y][x])) * pix, fdf);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

int	fdf_key_hook(int key, t_fdf *fdf)
{
	static int	n;
	static int 	m;
	static int	zoom = 8;

	if (key == ESC)
	{
		free_all(fdf);
		exit(0);
	}
	if (key == LEFT)
	{
		n++;
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
		put_line(fdf, n, m, zoom);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	}
	if (key == RIGHT)
	{
		n--;
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
		put_line(fdf, n, m, zoom);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	}
	if (key == UP)
	{	m--;
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
		put_line(fdf, n, m, zoom);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	}
	if (key == DOWN)
	{	m++;
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
		put_line(fdf, n, m, zoom);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	}
	if (key == PLUS)
	{	zoom++;
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
		put_line(fdf, n, m, zoom);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	}
	if (key == MINUS)
	{	zoom--;
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
		put_line(fdf, n, m, zoom);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	}
	return (0);
}

int	click_cross(t_fdf *fdf)
{
	free_all(fdf);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	
	
	if (argc != 2)
		return (0);
	
	fdf = init_fdf(argv[1]);
	put_line(fdf, 0, 0, 8);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_hook(fdf->win, KeyPress, KeyPressMask, fdf_key_hook, fdf);
	mlx_hook(fdf->win, DestroyNotify, StructureNotifyMask, click_cross, fdf);
	// mlx_key_hook(fdf->win, fn(), fdf);
	
	
	
		

	mlx_loop(fdf->mlx);
	
	// free_map(fdf->map);
	
	return (0);
}

/*
iso_x = (x - y) * cos(30°)
iso_y = (x + y) * sin(30°) - z
*/

// int	main(int argc, char ** argv)
// {
// 	// ft_printf("test\n");
// 	void	*xvar;
// 	int		fd;
// 	char	*str;
// 	void	*win;
// 	void	*img;

// 	int	origin_x = 960;
// 	int	origin_y = 540;
// 	int x = 0;
// 	int	z = 0;
// 	int y = 0;
// 	int	n = 0;

// 	fd = open(argv[1], O_RDONLY);

// 	xvar = mlx_init();
// 	win = mlx_new_window(xvar, 1920, 1080, "test"); /*mid = 960, 540*/
	
// 	str = get_next_line(fd);
// 	while (str[n])
// 	{
// 		if (str[n] == '\n')
// 			str[n] = 0;
// 		n++;
// 	}
// 	n = 0;
// 	char **line;
// 	char	**last_line;
// 	while (str)
// 	{
// 		x = 0;
// 		line = ft_split(str, ' ');
// 		while (line[x] && line[x][0] != '\n')
// 		{
// 			mlx_pixel_put(xvar, win, origin_x + (x - y) * cos(rad(30)) * 32, origin_y + ((x + y) * sin(rad(30)) - ft_atoi(line[x])) * 32, 0x00FF0000);
// 			if (x > 0)
// 			{
// 				// draw_line(origin_x + (x - 1 - y) * cos(rad(30)) * 32, origin_y + ((x - 1 + y) * sin(rad(30)) - ft_atoi(line[x])) * 32, origin_x + (x - y) * cos(rad(30)) * 32, origin_y + ((x + y) * sin(rad(30)) - ft_atoi(line[x])) * 32, xvar, win);
// 				draw_line(origin_x + (x - 1 - y) * cos(rad(30)) * 32, origin_y + ((x - 1 + y) * sin(rad(30)) - ft_atoi(line[x - 1])) * 32, origin_x + (x - y) * cos(rad(30)) * 32, origin_y + ((x + y) * sin(rad(30)) - ft_atoi(line[x])) * 32, xvar, win);
// 			}
// 			if (y > 0)
// 			{
// 				draw_line(origin_x + (x - y + 1) * cos(rad(30)) * 32, origin_y + ((x + y - 1) * sin(rad(30)) - ft_atoi(last_line[x])) * 32, origin_x + (x - y) * cos(rad(30)) * 32, origin_y + ((x + y) * sin(rad(30)) - ft_atoi(line[x])) * 32, xvar, win);
// 				// draw_line(origin_x + (x - y) * cos(rad(30)) * 32, origin_y + ((x + y) * sin(rad(30)) - ft_atoi(line[x])) * 32, origin_x + (x - y + 1) * cos(rad(30)) * 32, origin_y + ((x + y - 1) * sin(rad(30)) - ft_atoi(last_line[x])) * 32, xvar, win);
// 			}
// 			x++;
// 		}
// 		last_line = line;
// 		free(str);
// 		free(line);
// 		str = get_next_line(fd);
// 		while (str && str[n])
// 		{
// 			if (str[n] == '\n')
// 				str[n] = 0;
// 			n++;
// 		}
// 		n = 0;
// 		y++;

// 	}
// 	mlx_loop(xvar);

// 	return (0);
// }


