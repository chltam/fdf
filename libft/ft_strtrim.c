/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:52:27 by htam              #+#    #+#             */
/*   Updated: 2022/12/04 13:52:28 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int			n;
	int			i;
	char		*newstr;

	n = 0;
	i = ft_strlen(s1);
	while (s1[n] && ft_strchr(set, s1[n]))
		n++;
	while (ft_strchr(set, s1[i - 1]) && i > n)
		i--;
	newstr = ft_substr(s1, n, i - n);
	if (!newstr)
		return (NULL);
	return (newstr);
}
