/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:46:49 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/13 11:48:31 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(char *format, va_list *arg)
{
	t_data	data;

	data.contor = 0;
	while (*format)
	{
		if (format[0] == '%' && format[1] == '\0')
			return (data.contor);
		if (*format == '%')
		{
			format++;
			data.contor += print_specifier(&format, arg, &data);
			continue ;
		}
		ft_putchar(*format);
		format++;
		data.contor++;
	}
	return (data.contor);
}
