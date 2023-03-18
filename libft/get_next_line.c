/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:29:38 by htam              #+#    #+#             */
/*   Updated: 2023/02/28 19:28:50 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlcheck(char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (-1);
	while (s[n])
	{
		if (s[n] == '\n')
			return (n);
		n++;
	}
	if (s[n] == 0)
		return (n);
	return (-1);
}

char	*ft_readandstash(int fd, char *buff, char *stash)
{
	int	read_count;

	read_count = 1;
	if (!stash)
		stash = ft_strdup("");
	while (read_count > 0 && !ft_strchr(stash, '\n'))
	{
		read_count = read(fd, buff, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(stash);
			return (NULL);
		}
		buff[read_count] = 0;
		stash = ft_strjoin_free_s1(stash, buff);
	}
	if (stash[0] == 0)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

char	*ft_trimstash(char *stash)
{
	int		nlpos;
	char	*output;

	nlpos = ft_nlcheck(stash);
	output = ft_substr(stash, 0, nlpos + 1);
	return (output);
}

char	*ft_newstash(char *stash)
{
	int		stash_len;
	int		nlpos;
	char	*newstr;

	stash_len = ft_strlen(stash);
	nlpos = ft_nlcheck(stash);
	newstr = ft_substr(stash, nlpos + 1, stash_len - nlpos);
	free(stash);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*output;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(*buff) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	stash = ft_readandstash(fd, buff, stash);
	free(buff);
	if (!stash)
		return (0);
	output = ft_trimstash(stash);
	if (ft_strlen(output) == 0)
		return (NULL);
	stash = ft_newstash(stash);
	return (output);
}
