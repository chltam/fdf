/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:52:54 by htam              #+#    #+#             */
/*   Updated: 2022/11/28 16:31:21 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>

int	main()
{
	
	char str[50] = "GeeksForGeeks is for programming geeks.";
	char str2[10] = "123456789";
	printf("\nBefore memset(): %s\n", str);
	printf("%s\n", (char *)ft_memset(str2, 'a', 5));
	ft_memset(str + 13, '.', 8);
	printf("After memset():  %s", str);
	
	return (0);
}
*/