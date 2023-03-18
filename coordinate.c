/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:15:05 by htam              #+#    #+#             */
/*   Updated: 2023/03/18 16:23:33 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cart	make_cart(double x, double y, double z)
{
	t_cart	cart;

	cart.x = x;
	cart.y = y;
	cart.z = z;
	return (cart);
}

t_iso	cart_to_iso(t_cart cart)
{
	t_iso	iso;

	iso.x = (cart.x - cart.y) * cos(rad(30));
	iso.y = (cart.x + cart.y) * sin(rad(30)) - cart.z;
	return (iso);
}

t_iso	iso_rotate(t_cart cart, t_move move)
{
	t_iso	iso;

	cart = rotate_around_x(cart, move);
	cart = rotate_around_y(cart, move);
	cart = rotate_around_z(cart, move);
	iso = cart_to_iso(cart);
	return (iso);
}

t_iso	transform_iso(t_iso in, t_move move)
{
	t_iso	out;

	out.x = ORIGIN_X + in.x * move.zoom + move.offset_x;
	out.x = (int)round(out.x);
	out.y = ORIGIN_Y + in.y * move.zoom + move.offset_y;
	out.y = (int)round(out.y);
	return (out);
}
