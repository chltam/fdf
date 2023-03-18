/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:39:37 by htam              #+#    #+#             */
/*   Updated: 2023/01/03 23:39:39 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hex_digitcount(unsigned long long number)
{
	int	count;

	count = 1;
	while (number >= 16)
	{
		number = number / 16;
		count++;
	}
	return (count);
}

char	*ft_hex(unsigned long long number, char *base)
{
	int					count;
	char				*str;

	count = ft_hex_digitcount(number);
	str = malloc(sizeof(*str) * (count + 1));
	if (!str)
		return (0);
	str[count] = 0;
	count--;
	while (count >= 0)
	{
		str[count] = base[number % 16];
		number /= 16;
		count--;
	}
	return (str);
}

int	ft_format_hex_lowercase(va_list arg)
{
	char				*str;
	unsigned long long	number;
	int					len;

	number = va_arg(arg, unsigned int);
	str = ft_hex(number, "0123456789abcdef");
	len = ft_putstr_len(str);
	free(str);
	return (len);
}

int	ft_format_hex_uppercase(va_list arg)
{
	char				*str;
	unsigned long long	number;
	int					len;

	number = va_arg(arg, unsigned int);
	str = ft_hex(number, "0123456789ABCDEF");
	len = ft_putstr_len(str);
	free(str);
	return (len);
}

int	ft_format_pointer(va_list arg)
{
	char				*str;
	unsigned long long	number;
	int					len;

	number = va_arg(arg, unsigned long long);
	if (number == 0)
		return (write(1, "(nil)", 5));
	str = ft_hex(number, "0123456789abcdef");
	len = write(1, "0x", 2) + ft_putstr_len(str);
	free(str);
	return (len);
}
