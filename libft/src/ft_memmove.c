/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:12:09 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 14:30:05 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned	char	*a;
	unsigned	char	*b;
	size_t				i;

	i = -1;
	a = (unsigned	char*)dst;
	b = (unsigned	char*)src;
	if (a > b)
		while (len-- > 0)
			a[len] = b[len];
	else
		while (++i < len)
			a[i] = b[i];
	return (dst);
}
