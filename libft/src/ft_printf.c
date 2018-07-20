/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:14:45 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/01 13:14:47 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	int			contor;

	va_start(arg, format);
	contor = print_string((char *)format, &arg);
	va_end(arg);
	return (contor);
}

int		print_specifier(char **format, va_list *arg, t_data *data)
{
	int		ret;

	init_data(data);
	parse_flags(format, data);
	parse_width(format, arg, data);
	parse_precision(format, arg, data);
	parse_length(format, data);
	ret = parse_specifiers(format, arg, data);
	return (ret);
}
