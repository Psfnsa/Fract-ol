/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:15:35 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/05 17:28:12 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		octal_handle(va_list *arg, t_data *data)
{
	unsigned long long int	num;
	char					*str;
	int						ret;

	num = extract_ulength(arg, data);
	str = ft_itoa_ulong(num, 8, 0);
	if (data->dot)
		data->zero = 0;
	if (data->dot && data->precision > 0)
		data->diez = 0;
	if (data->dot && data->precision == 0 && num == 0)
		return (apply_flags("", data, (data->diez) ? "0" : ""));
	if (data->diez && num != 0)
		ret = apply_flags(str, data, "0");
	else
		ret = apply_flags(str, data, "");
	free(str);
	return (ret);
}
