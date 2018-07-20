/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:32:58 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/13 12:15:50 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_specifiers(char **format, va_list *arg, t_data *data)
{
	if (**format == 'd' || **format == 'i')
	{
		(*format)++;
		return (int_handle(arg, data));
	}
	else if (**format == 'u')
	{
		(*format)++;
		return (unsigned_handle(arg, data));
	}
	else if (**format == 'x')
	{
		(*format)++;
		return (hex_handle(arg, data, 0));
	}
	else if (**format == 'X')
	{
		(*format)++;
		return (hex_handle(arg, data, 1));
	}
	return (parse_specifiers2(format, arg, data));
}

int		parse_specifiers2(char **format, va_list *arg, t_data *data)
{
	if (**format == 'o')
	{
		(*format)++;
		return (octal_handle(arg, data));
	}
	else if (**format == 'D')
	{
		(*format)++;
		data->l = 1;
		return (int_handle(arg, data));
	}
	else if (**format == 'U')
	{
		(*format)++;
		data->l = 1;
		return (unsigned_handle(arg, data));
	}
	else if (**format == 'O')
	{
		(*format)++;
		data->l = 1;
		return (octal_handle(arg, data));
	}
	return (parse_specifiers3(format, arg, data));
}

int		parse_specifiers3(char **format, va_list *arg, t_data *data)
{
	if (**format == 'p')
	{
		(*format)++;
		return (adress_handle(arg, data));
	}
	else if (**format == 's')
	{
		(*format)++;
		return (string_handle(arg, data));
	}
	else if (**format == 'c')
	{
		(*format)++;
		return (char_handle(arg, data));
	}
	else if (**format == 'n')
	{
		(*format)++;
		return (n_handle(arg, data));
	}
	return (parse_specifiers4(format, arg, data));
}

int		parse_specifiers4(char **format, va_list *arg, t_data *data)
{
	if (**format == 'S')
	{
		(*format)++;
		return (widestr_handle(arg, data));
	}
	else if (**format == 'C')
	{
		(*format)++;
		return (widechar_handle(arg, data));
	}
	else if (**format == '%')
	{
		(*format)++;
		return (percent_handle(data));
	}
	else if (**format == 'b')
	{
		(*format)++;
		return (binary_handle(arg, data));
	}
	else
	{
		(*format)++;
		return (undefined_handle(data, *((*format) - 1)));
	}
}
