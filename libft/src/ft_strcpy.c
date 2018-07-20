/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:48:53 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 15:24:55 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t len;

	len = 0;
	while (src[len])
	{
		dst[len] = src[len];
		len++;
	}
	if (src[len] == '\0')
		dst[len] = '\0';
	return (dst);
}
