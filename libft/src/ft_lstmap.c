/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:06:54 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 13:48:02 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*cp;
	t_list	*k;

	tmp = NULL;
	cp = NULL;
	if (lst)
	{
		k = f(lst);
		if ((tmp = ft_lstnew(k->content, k->content_size)))
		{
			cp = tmp;
			while ((lst = lst->next))
			{
				k = f(lst);
				if (!(tmp->next = ft_lstnew(k->content, k->content_size)))
					return (NULL);
				tmp = tmp->next;
			}
		}
	}
	return (cp);
}
