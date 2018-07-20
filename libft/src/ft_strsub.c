/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:22:34 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/11 18:42:39 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = -1;
	if (s)
	{
		if (!(str = (char*)malloc(len + 1)))
			return (NULL);
		while (++i < len)
		{
			str[i] = s[start];
			start++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
