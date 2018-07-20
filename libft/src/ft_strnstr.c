/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:41:16 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 16:24:04 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;
	int		r;
	size_t	n;

	n = -1;
	i = 0;
	r = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0' && ++n <= len)
	{
		r = i;
		j = 0;
		while ((big[i] == little[j] || little[j] == '\0') && n <= len)
		{
			if (little[j] == '\0' && n <= len)
				return ((char*)big + r);
			j++;
			i++;
			n++;
		}
		i++;
	}
	return (NULL);
}
