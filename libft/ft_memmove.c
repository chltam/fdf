/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:16:55 by htam              #+#    #+#             */
/*   Updated: 2022/11/28 17:16:56 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (s > d)
		return (ft_memcpy(dest, src, n));
	if (s < d)
	{
		while (n != 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
  char csrc[100] = "Geeksfor";
  ft_memmove(csrc+5, csrc, strlen(csrc)+1);
  printf("%s", csrc);
  return 0;
}
*/