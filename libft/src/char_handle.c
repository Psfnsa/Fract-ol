/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:24:36 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/05 19:04:42 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		char_handle(va_list *arg, t_data *data)
{
	char	c;
	int		ret;

	if (data->l)
		return (widechar_handle(arg, data));
	c = (char)va_arg(*arg, int);
	data->width--;
	data->precision = 0;
	if (data->minus)
	{
		ft_putchar(c);
		ret = apply_flags("", data, "");
	}
	else
	{
		ret = apply_flags("", data, "");
		ft_putchar(c);
	}
	return (ret + 1);
}
