/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:46:03 by htam              #+#    #+#             */
/*   Updated: 2022/11/29 20:46:05 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[n] && n < len)
	{
		while (big[n + i] == little[i] && little[i] && n + i < len)
			i++;
		if (little[i] == 0)
			return ((char *)big + n);
		i = 0;
		n++;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main()
{
	char	b[] = "abcdefggg";
	char	l[] = "cf";
	printf("%s\n", ft_strnstr(b, l, 5));
	return 0;
}
*/