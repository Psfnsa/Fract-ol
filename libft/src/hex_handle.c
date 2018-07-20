/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:57:42 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/13 12:05:45 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hex_handle(va_list *arg, t_data *data, int case01)
{
	unsigned long long int	num;
	char					*str;
	int						ret;

	num = extract_ulength(arg, data);
	str = ft_itoa_ulong(num, 16, case01);
	if (data->dot)
		data->zero = 0;
	if (data->dot && data->precision == 0 && num == 0)
		return (apply_flags("", data, ""));
	if (data->diez && num != 0)
		ret = apply_flags(str, data, (case01) ? "0X" : "0x");
	else
		ret = apply_flags(str, data, "");
	free(str);
	return (ret);
}
