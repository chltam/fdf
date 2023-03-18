/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:57:42 by htam              #+#    #+#             */
/*   Updated: 2022/12/26 20:57:44 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static const t_format	g_dispatchtable[] = {
['c'] = ft_format_char,
['s'] = ft_format_string,
['p'] = ft_format_pointer,
['d'] = ft_format_decimal,
['i'] = ft_format_decimal,
['u'] = ft_format_unsigned,
['x'] = ft_format_hex_lowercase,
['X'] = ft_format_hex_uppercase,
['%'] = ft_format_percent
};

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		n;
	int		len;

	len = 0;
	n = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[n])
	{
		if (str[n] == '%' && g_dispatchtable[(int)str[n + 1]])
		{
			len += g_dispatchtable[(int)str[n + 1]](args);
			n++;
		}
		else
			len += write(1, &str[n], 1);
		n++;
	}
	va_end(args);
	return (len);
}
