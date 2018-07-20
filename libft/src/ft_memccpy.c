/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:11:49 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 14:26:38 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned	char	*a;
	unsigned	char	*b;
	unsigned	char	x;

	x = (unsigned char)c;
	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	while (n-- > 0)
	{
		if (*b != x)
		{
			*a = *b;
			a++;
			b++;
		}
		else
			break ;
	}
	if ((int)n != -1)
	{
		*a = *b;
		return (a + 1);
	}
	return (NULL);
}
