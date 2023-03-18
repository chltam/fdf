/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:25:45 by htam              #+#    #+#             */
/*   Updated: 2023/03/18 16:28:40 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
// # include <mlx.h>
// # include <mlx_int.h>
# include <math.h>

# define M_PI 3.14159265358979323846
# define ORIGIN_X 960
# define ORIGIN_Y 540

# define ESC     65307

# define UP      65362
# define DOWN    65364
# define LEFT    65361
# define RIGHT   65363

# define PLUS    65451
# define MINUS   65453

# define W_KEY   119
# define A_KEY   97
# define S_KEY   115
# define D_KEY   100
# define Q_KEY   113
# define E_KEY   101

# define C_KEY   99
# define R_KEY   114
# define G_KEY   103
# define B_KEY   98
# define Y_KEY   121

typedef struct s_move
{
	int				rotate_x;
	int				rotate_y;
	int				rotate_z;
	int				zoom;
	int				offset_x;
	int				offset_y;
	unsigned int	color;
}	t_move;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	char	***map;
	int		bpp;
	int		size_line;
	int		endian;
	t_move	move;
}	t_fdf;

typedef struct s_cart
{
	double	x;
	double	y;
	double	z;
}	t_cart;

typedef struct s_iso
{
	double	x;
	double	y;
}	t_iso;

char	***init_map(char *file);
t_fdf	*init_fdf(char *file);
double	rad(double deg);
t_cart	make_cart(double x, double y, double z);
t_iso	cart_to_iso(t_cart cart);
t_iso	iso_rotate(t_cart cart, t_move move);
t_iso	transform_iso(t_iso in, t_move move);
void	put_pix_to_img(t_fdf *fdf, int x, int y);
t_cart	rotate_around_x(t_cart in, t_move move);
t_cart	rotate_around_y(t_cart in, t_move move);
t_cart	rotate_around_z(t_cart in, t_move move);
void	put_line(t_fdf *fdf, t_move move, int key);
void	draw_line(t_iso iso0, t_iso iso1, t_fdf *fdf);
void	remake_img(t_fdf *fdf, int key);
void	wasdqe_hook(int KEY, t_fdf *fdf);
void	udlr_hook(int KEY, t_fdf *fdf);
void	pm_hook(int key, t_fdf *fdf);
void	rgb_hook(int key, t_fdf *fdf);
void	free_all(t_fdf *fdf);
int		free_and_exit(t_fdf *fdf);

#endif