/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:22:25 by htam              #+#    #+#             */
/*   Updated: 2022/11/30 12:22:26 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	positiveflag;
	int	rei;

	n = 0;
	positiveflag = 1;
	rei = 0;
	while ((nptr[n] >= 9 && nptr[n] <= 13) || nptr[n] == 32)
		n++;
	if (nptr[n] == '+' || nptr[n] == '-')
	{
		if (nptr[n] == '-')
			positiveflag *= -1;
		n++;
	}
	if (!ft_isdigit(nptr[n]))
		return (0);
	while (nptr[n] && ft_isdigit(nptr[n]))
	{
		rei = rei * 10 + nptr[n] - 48;
		n++;
	}
	return (rei * positiveflag);
}

/*int main()
{
	printf("%d\n", atoi("   2147483647h12333"));
	printf("%d\n", ft_atoi("   +++-2147483648h12333"));
	printf("%d\n", atoi("   +++-2147483648h12333"));
	return 0;
}*/
