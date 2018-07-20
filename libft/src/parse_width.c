/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:48:02 by mabanciu          #+#    #+#             */
/*   Updated: 2018/03/30 19:12:13 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(char **format, va_list *arg, t_data *data)
{
	while (1)
	{
		if (ft_isdigit(**format))
		{
			data->width = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (**format == '*')
		{
			(*format)++;
			data->width = va_arg(*arg, int);
			if (data->width < 0)
			{
				data->width *= -1;
				data->minus = 1;
			}
		}
		else
			break ;
	}
}
