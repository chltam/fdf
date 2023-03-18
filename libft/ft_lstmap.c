/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:57:07 by htam              #+#    #+#             */
/*   Updated: 2022/12/08 15:57:08 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*element;

	if (!lst || !f)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		element = ft_lstnew(f(lst -> content));
		if (!element)
		{
			ft_lstclear(&element, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&newlist, element);
		lst = lst -> next;
	}
	return (newlist);
}
