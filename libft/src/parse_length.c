/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:26:05 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/02 14:57:34 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_length(char **format, t_data *data)
{
	if ((*format)[0] == 'l' && (*format)[1] == 'l')
		data->ll = 1;
	else if ((*format)[0] == 'h' && (*format)[1] == 'h')
		data->hh = 1;
	else if ((*format)[0] == 'h')
		data->h = 1;
	else if ((*format)[0] == 'l')
		data->l = 1;
	else if ((*format)[0] == 'j')
		data->j = 1;
	else if ((*format)[0] == 'z')
		data->z = 1;
	if (data->ll || data->hh)
		(*format) += 2;
	else if (data->h || data->l || data->j || data->z)
		(*format)++;
}
