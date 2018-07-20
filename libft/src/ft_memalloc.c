/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:47:54 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 14:26:22 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char*)malloc(size)))
		return (NULL);
	while (i < (int)size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
