/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:48:24 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/07 12:48:45 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		binary_handle(va_list *arg, t_data *data)
{
	unsigned long long int	num;
	char					*str;
	int						ret;

	num = extract_ulength(arg, data);
	str = ft_itoa_ulong(num, 2, 0);
	if (data->dot)
		data->zero = 0;
	if (data->dot && data->precision == 0 && num == 0)
		return (apply_flags("", data, ""));
	ret = apply_flags(str, data, "");
	free(str);
	return (ret);
}
