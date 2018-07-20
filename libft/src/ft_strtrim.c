/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:33:06 by mabanciu          #+#    #+#             */
/*   Updated: 2017/12/18 16:10:45 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	long long	i;
	size_t		j;
	long long	k;
	char		*str;

	j = 0;
	i = 0;
	if (s)
	{
		k = ft_strlen(s) - 1;
		while (!(s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
			i++;
		while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
			k--;
		if ((k + 1 - i) < 0)
			str = (char*)malloc(1);
		else if (!(str = (char*)malloc((k - i + 2) * sizeof(char))))
			return (NULL);
		while (i <= k)
			str[j++] = s[i++];
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
