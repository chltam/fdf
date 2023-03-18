/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:48:51 by htam              #+#    #+#             */
/*   Updated: 2022/11/29 18:48:53 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	dst_len;

	n = 0;
	dst_len = ft_strlen(dst);
	if (dst_len >= size)
		dst_len = size;
	while (src[n] && (dst_len + n + 1) < size)
	{
		dst[dst_len + n] = src[n];
		n++;
	}
	if (dst_len < size)
		dst[dst_len + n] = 0;
	return (dst_len + ft_strlen(src));
}
