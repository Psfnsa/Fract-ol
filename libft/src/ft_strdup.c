/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:50:03 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 15:25:13 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	if (!(s2 = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	while (len <= i)
	{
		s2[len] = s1[len];
		len++;
	}
	return (s2);
}
