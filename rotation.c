/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:33:03 by htam              #+#    #+#             */
/*   Updated: 2023/03/17 16:58:13 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cart	rotate_around_x(t_cart in, t_move move)
{
	t_cart	out;

	out.x = in.x;
	out.y = in.y * cos(rad(move.rotate_x)) - in.z * sin(rad(move.rotate_x));
	out.z = in.y * sin(rad(move.rotate_x)) + in.z * cos(rad(move.rotate_x));
	return (out);
}

t_cart	rotate_around_y(t_cart in, t_move move)
{
	t_cart	out;

	out.x = in.x * cos(rad(move.rotate_y)) + in.z * sin(rad(move.rotate_y));
	out.y = in.y;
	out.z = -in.x * sin(rad(move.rotate_y)) + in.z * cos(rad(move.rotate_y));
	return (out);
}

t_cart	rotate_around_z(t_cart in, t_move move)
{
	t_cart	out;

	out.x = in.x * cos(rad(move.rotate_z)) - in.y * sin(rad(move.rotate_z));
	out.y = in.x * sin(rad(move.rotate_z)) + in.y * cos(rad(move.rotate_z));
	out.z = in.z;
	return (out);
}
