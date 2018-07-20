/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:22:05 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/16 10:57:46 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
			while ((int)len > i)
			{
				dst[i] = '\0';
				i++;
			}
		i++;
	}
	return (dst);
}
