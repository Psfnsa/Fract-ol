/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:21:52 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 14:28:51 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned	char	*a;
	unsigned	char	*b;

	a = (unsigned	char*)dst;
	b = (unsigned	char*)src;
	while (n-- > 0)
	{
		a[n] = b[n];
	}
	return (dst);
}
