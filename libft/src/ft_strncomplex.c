/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncomplex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:42:46 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/23 11:42:47 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncomplex(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = -1;
	while (s1[i] == s2[i] && ++n < len && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (++n == len || i != len)
		return (0);
	else
		return (1);
}
