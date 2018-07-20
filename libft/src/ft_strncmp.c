/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:28:44 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/09 16:01:55 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	int		i;
	size_t	n;

	i = 0;
	n = -1;
	while (s1[i] == s2[i] && ++n < len && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (++n == len)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
