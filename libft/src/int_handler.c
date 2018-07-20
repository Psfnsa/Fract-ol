/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:49:44 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/13 12:16:49 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			int_handle(va_list *arg, t_data *data)
{
	long long int	num;
	char			*str;
	int				ret;

	num = extract_length(arg, data);
	str = ft_itoa_long(num);
	if (data->dot && data->precision > 0)
		data->zero = 0;
	if (data->dot && data->precision == 0 && num == 0)
		return (apply_flags("", data, ""));
	if (num < 0)
		ret = apply_flags(str + 1, data, "-");
	else if (data->plus)
		ret = apply_flags(str, data, "+");
	else if (data->space)
		ret = apply_flags(str, data, " ");
	else
		ret = apply_flags(str, data, "");
	free(str);
	return (ret);
}

long long	extract_length(va_list *arg, t_data *data)
{
	if (data->l)
		return ((long long)va_arg(*arg, long int));
	else if (data->ll)
		return (va_arg(*arg, long long int));
	else if (data->hh)
		return ((char)va_arg(*arg, int));
	else if (data->h)
		return ((short int)va_arg(*arg, int));
	else if (data->j)
		return ((long long int)va_arg(*arg, intmax_t));
	else if (data->z)
		return ((long long int)va_arg(*arg, size_t));
	else
		return (va_arg(*arg, int));
}
