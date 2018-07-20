/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:42:31 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/05 19:48:34 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent_handle(t_data *data)
{
	int		ret;

	data->precision = 0;
	ret = apply_flags("%", data, "");
	return (ret);
}
