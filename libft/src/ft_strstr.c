/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:54:23 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/15 10:42:41 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int r;

	i = 0;
	r = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		r = i;
		j = 0;
		while (big[i] == little[j] || little[j] == '\0')
		{
			if (little[j] == '\0')
				return ((char*)big + r);
			j++;
			i++;
		}
		i = r + 1;
	}
	return (NULL);
}
