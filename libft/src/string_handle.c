/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:05:53 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/05 18:17:41 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string_handle(va_list *arg, t_data *data)
{
	char	*str;
	int		ret;

	if (data->l)
		return (widestr_handle(arg, data));
	str = va_arg(*arg, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (data->dot && (int)ft_strlen(str) > data->precision)
		str[data->precision] = '\0';
	data->precision = 0;
	ret = apply_flags(str, data, "");
	free(str);
	return (ret);
}
