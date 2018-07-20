/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:57:46 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/02 15:21:48 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_precision(char **format, va_list *arg, t_data *data)
{
	if (**format == '.')
	{
		data->dot = 1;
		(*format)++;
		if (ft_isdigit(**format))
		{
			data->precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (**format == '*')
		{
			(*format)++;
			data->precision = va_arg(*arg, int);
		}
	}
}
