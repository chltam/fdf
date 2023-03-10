/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:25:45 by htam              #+#    #+#             */
/*   Updated: 2023/03/10 18:12:55 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include "./mlx_linux/mlx_int.h"
// #include <mlx.h>
// #include <mlx_int.h>
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
# define C_KEY   99

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

}	t_fdf;

typedef struct s_iso
{
	double	x;
	double	y;
}	t_iso;

char	***init_map(char *file);
void	put_pix_to_img(t_fdf *fdf, int x, int y);
t_fdf	*init_fdf(char *file);
void	free_all(t_fdf *fdf);

#endif