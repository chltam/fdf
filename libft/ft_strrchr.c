/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:38:49 by htam              #+#    #+#             */
/*   Updated: 2022/11/28 13:38:51 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;
	int		n;

	str = (char *)s;
	ch = (char)c;
	n = ft_strlen(s);
	while (str[n] != ch && n > 0)
		n--;
	if (str[n] == ch)
		return (str + n);
	return (NULL);
}
/*
#include <stdio.h>
int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = 'g';
   char *ret;

   ret = ft_strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}*/
