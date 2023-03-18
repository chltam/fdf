/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:24:15 by htam              #+#    #+#             */
/*   Updated: 2022/12/04 16:24:16 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	n;
	int	count;

	n = 0;
	count = 0;
	if (n == 0 && s[n])
	{
		if (s[n] != c)
			count++;
		n++;
	}
	while (s[n])
	{
		if (s[n - 1] == c && s[n] != c)
			count++;
		n++;
	}
	return (count);
}

static int	charcount(char const *s, char c)
{
	int	n;

	n = 0;
	while (s[n] != c && s[n])
		n++;
	return (n);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**str;
	int		n;
	int		count;

	n = 0;
	count = 0;
	word = wordcount(s, c);
	str = malloc(sizeof(*str) * (word + 1));
	if (!str)
		return (0);
	str[word] = 0;
	while (count < word)
	{
		while (s[n] && s[n] == c)
			n++;
		str[count] = ft_substr(s + n, 0, charcount(s + n, c));
		while (s[n] && s[n] != c)
			n++;
		count++;
	}
	return (str);
}
