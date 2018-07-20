/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:53:14 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 16:32:21 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	int	i;
	int k;
	int	count;

	count = 0;
	k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && count == 1)
			count = 0;
		if (s[i] != c && count == 0)
		{
			count = 1;
			k++;
		}
		i++;
	}
	return (k);
}

static char		**ft_string(char **str, char const *s, char c)
{
	size_t	j;
	size_t	i;
	int		k;
	size_t	x;

	i = 0;
	k = 0;
	while (i < count(s, c))
	{
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k++] != c)
			j++;
		if (!(str[i] = (char*)malloc((j + 1) * sizeof(char))))
			return (NULL);
		x = 0;
		k = k - j - 1;
		while (x < j)
			str[i][x++] = s[k++];
		str[i][x] = '\0';
		i++;
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;

	if (s)
	{
		if (!(str = (char**)malloc(sizeof(char*) * (count(s, c) + 1))))
			return (NULL);
		str[count(s, c)] = NULL;
		str = ft_string(str, s, c);
		return (str);
	}
	return (NULL);
}
