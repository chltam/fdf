/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:33:47 by htam              #+#    #+#             */
/*   Updated: 2022/12/05 17:33:49 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	digitcount(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*fillboxes(char *str, int n, int i)
{
	while (--i >= 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		negative;
	char	*str;

	negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	i = digitcount(n);
	str = malloc(sizeof(*str) * i + negative + 1);
	if (!str)
		return (NULL);
	str[i] = 0;
	str = fillboxes(str, n, i);
	if (negative == 1)
	{
		ft_memmove(str + 1, str, ft_strlen(str) + 1);
		str[0] = '-';
	}
	return (str);
}
