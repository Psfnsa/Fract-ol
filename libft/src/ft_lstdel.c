/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:17:00 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 13:45:15 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*nxt;

	tmp = *alst;
	nxt = tmp->next;
	while (tmp->next)
	{
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = nxt;
		nxt = tmp->next;
	}
	del(tmp->content, tmp->content_size);
	free(tmp);
	*alst = NULL;
}
