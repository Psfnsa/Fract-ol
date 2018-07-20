/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:47:24 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/05 16:26:53 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa_isnegative(long long int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char		*ft_itoa_long(long long int n)
{
	long long int		tmpn;
	int					len;
	int					negative;
	char				*str;

	if (n == (-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
	tmpn = n;
	len = 2;
	negative = 0;
	itoa_isnegative(&n, &negative);
	while (tmpn /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char		*ft_itoa_ulong(unsigned long long int n, int base, int case01)
{
	unsigned long long int	tmpn;
	int						len;
	int						temp;
	char					*str;

	tmpn = n;
	len = 2;
	while (tmpn /= base)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		temp = n % base;
		if (temp > 9)
			str[len] = temp + ((case01) ? 55 : 87);
		else
			str[len] = temp + '0';
		n = n / base;
	}
	return (str);
}
