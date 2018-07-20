/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:08:37 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/07 12:08:40 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		undefined_handle(t_data *data, char c)
{
	int		ret;

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
