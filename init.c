/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:14:34 by htam              #+#    #+#             */
/*   Updated: 2023/03/18 16:44:21 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_line(char *file)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(file, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

void	remove_n(char *line)
{
	int	n;

	n = 0;
	if (!line)
		return ;
	while (line[n])
	{
		if (line[n] == '\n')
			line[n] = 0;
		n++;
	}
}

char	***init_map(char *file)
{
	int		fd;
	char	*line;
	char	***map;
	int		y;

	y = count_line(file);
	map = malloc(sizeof(*map) * (y + 1));
	if (!map)
		return (NULL);
	map[y] = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	remove_n(line);
	y = 0;
	while (line)
	{
		map[y] = ft_split(line, ' ');
		free(line);
		line = get_next_line(fd);
		remove_n(line);
		y++;
	}
	free(line);
	close(fd);
	return (map);
}

t_move	init_move(void)
{
	t_move	move;

	move.rotate_x = 0;
	move.rotate_y = 0;
	move.rotate_z = 0;
	move.zoom = 8;
	move.offset_x = 0;
	move.offset_y = 0;
	move.color = 0xFFFFFFFF;
	return (move);
}

t_fdf	*init_fdf(char *file)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(*fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		free_and_exit(fdf);
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "fdf");
	fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
	if (!fdf->win || ! fdf->img)
		free_and_exit(fdf);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->size_line, &fdf->endian);
	fdf->map = init_map(file);
	if (!fdf->data_addr || !fdf->map)
		free_and_exit(fdf);
	fdf->move = init_move();
	return (fdf);
}
