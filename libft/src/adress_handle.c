/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:48:36 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/05 19:46:45 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		adress_handle(va_list *arg, t_data *data)
{
	unsigned long long	num;
	void				*p;
	char				*str;
	int					ret;

	p = va_arg(*arg, void*);
	num = (unsigned long long)p;
	str = ft_itoa_ulong(num, 16, 0);
	if (num == 0 && data->dot)
		ret = apply_flags("", data, "0x");
	else
		ret = apply_flags(str, data, "0x");
	return (ret);
}
