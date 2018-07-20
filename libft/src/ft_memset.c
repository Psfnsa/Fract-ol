/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:34:17 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 14:30:16 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int i, size_t len)
{
	unsigned char	*b;

	b = (unsigned char*)str;
	while (len > 0)
	{
		*b = i;
		b++;
		len--;
	}
	return (str);
}
