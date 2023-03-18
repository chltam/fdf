/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:56:35 by htam              #+#    #+#             */
/*   Updated: 2022/11/30 12:56:36 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		n;
	unsigned int		i;
	char				*substr;

	n = 0;
	i = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(*substr) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[n])
	{
		if (n >= start && i < len)
		{
			substr[i] = s[n];
			i++;
		}
		n++;
	}
	substr[i] = 0;
	return (substr);
}
