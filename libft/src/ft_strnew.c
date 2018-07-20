/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:45:15 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/11 12:12:59 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*str;

	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i <= (int)size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
