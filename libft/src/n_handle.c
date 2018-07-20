/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:06:36 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/05 19:47:34 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		n_handle(va_list *arg, t_data *data)
{
	if (data->hh)
		*va_arg(*arg, char *) = data->contor;
	else if (data->h)
		*va_arg(*arg, short int *) = data->contor;
	else if (data->h)
		*va_arg(*arg, long int *) = data->contor;
	else if (data->h)
		*va_arg(*arg, long long int *) = data->contor;
	else if (data->j)
		*va_arg(*arg, intmax_t *) = data->contor;
	else if (data->z)
		*va_arg(*arg, size_t *) = data->contor;
	else
		*va_arg(*arg, int *) = data->contor;
	return (0);
}
