/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:44:16 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 13:44:50 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_while(int n, int len, int i, char *str)
{
	int x;

	x = 1;
	if (n < 0)
		x = -1;
	while (len >= i)
	{
		str[len--] = (n % 10) * x + '0';
		n = n / 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		k;
	int		i;

	i = 0;
	len = 1;
	k = n;
	if (k < 0)
		len++;
	while (k /= 10)
		len++;
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (n < 0)
		str[i++] = '-';
	str[len--] = '\0';
	str = ft_while(n, len, i, str);
	return (str);
}
