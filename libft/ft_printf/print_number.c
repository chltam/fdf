/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:39:07 by htam              #+#    #+#             */
/*   Updated: 2023/01/03 16:39:08 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_format_decimal(va_list arg)
{
	int		number;
	char	*str;
	int		len;

	number = va_arg(arg, int);
	str = ft_itoa(number);
	len = ft_putstr_len(str);
	free(str);
	return (len);
}

int	ft_us_digitcount(unsigned int number)
{
	int	count;

	count = 1;
	while (number >= 10)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

int	ft_format_unsigned(va_list arg)
{
	unsigned int	number;
	int				count;
	char			*str;
	int				len;

	number = va_arg(arg, unsigned int);
	count = ft_us_digitcount(number);
	str = malloc(sizeof(str) * (count + 1));
	if (!str)
		return (0);
	str[count] = 0;
	count--;
	while (count >= 0)
	{
		str[count] = (number % 10) + 48;
		number /= 10;
		count--;
	}
	len = ft_putstr_len(str);
	free(str);
	return (len);
}
