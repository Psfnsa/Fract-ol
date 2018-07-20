/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:12:56 by mabanciu          #+#    #+#             */
/*   Updated: 2018/03/30 18:13:57 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_data(t_data *data)
{
	data->minus = 0;
	data->plus = 0;
	data->space = 0;
	data->diez = 0;
	data->zero = 0;
	data->width = 0;
	data->precision = 0;
	data->dot = 0;
	data->hh = 0;
	data->h = 0;
	data->ll = 0;
	data->l = 0;
	data->j = 0;
	data->z = 0;
	data->prefix = 0;
}
