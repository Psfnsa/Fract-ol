/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:08:38 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 14:27:10 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	x;

	x = (unsigned char)c;
	a = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (a[i] == x)
			return ((void*)s + i);
		i++;
	}
	return (NULL);
}
