/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:34:40 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 14:29:01 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	char	*a;
	unsigned	char	*b;
	int					i;
	int					d;

	d = 0;
	i = 0;
	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	while (i < (int)n)
	{
		if (a[i] != b[i])
		{
			d = a[i] - b[i];
			return (d);
		}
		i++;
	}
	return (0);
}
