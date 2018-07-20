/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:34:42 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/16 12:30:03 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		if (!(str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			str[i] = s2[j];
			i++;
			j++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
