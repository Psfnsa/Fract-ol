/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:35:06 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/05 16:53:55 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	extract_ulength(va_list *arg, t_data *data)
{
	if (data->l)
		return ((unsigned long)va_arg(*arg, unsigned long int));
	else if (data->ll)
		return (va_arg(*arg, unsigned long long int));
	else if (data->hh)
		return ((unsigned char)va_arg(*arg, unsigned int));
	else if (data->h)
		return ((unsigned short int)va_arg(*arg, unsigned int));
	else if (data->j)
		return ((unsigned long long int)va_arg(*arg, uintmax_t));
	else if (data->z)
		return ((unsigned long long int)va_arg(*arg, size_t));
	else
		return (va_arg(*arg, unsigned int));
}

int					unsigned_handle(va_list *arg, t_data *data)
{
	unsigned long long int	num;
	char					*str;
	int						ret;

	num = extract_ulength(arg, data);
	str = ft_itoa_ulong(num, 10, 0);
	if (data->dot)
		data->zero = 0;
	if (data->dot && data->precision == 0 && num == 0)
		return (apply_flags("", data, ""));
	ret = apply_flags(str, data, "");
	free(str);
	return (ret);
}
