/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:53:04 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 16:37:59 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s)
{
	int count;
	int n;
	int i;

	i = 0;
	n = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == ' ' || s[i] == '\t') && count == 1)
			count = 0;
		if (s[i] != ' ' && s[i] != '\t' && count == 0)
		{
			count = 1;
			n++;
		}
		i++;
	}
	return (n);
}
