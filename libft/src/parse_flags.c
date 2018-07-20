/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:26:19 by mabanciu          #+#    #+#             */
/*   Updated: 2018/03/30 18:32:04 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(char **format, t_data *data)
{
	while (1)
	{
		if (**format == '-')
			data->minus = 1;
		else if (**format == '+')
			data->plus = 1;
		else if (**format == ' ')
			data->space = 1;
		else if (**format == '#')
			data->diez = 1;
		else if (**format == '0')
			data->zero = 1;
		else
			break ;
		(*format)++;
	}
}
