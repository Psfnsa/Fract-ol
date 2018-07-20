/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:24:36 by mabanciu          #+#    #+#             */
/*   Updated: 2018/04/05 16:24:40 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			precision_len(char *str, t_data *data)
{
	int		len;

	len = ft_strlen(str);
	if (data->precision > len)
		return (data->precision);
	else
		return (len);
}

void		print_pad(int len, char c)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putchar(c);
		i++;
	}
}

void		precision_print(char *str, t_data *data)
{
	int		len;

	len = data->precision - ft_strlen(str);
	if (len > 0)
	{
		print_pad(len, '0');
		ft_putstr(str);
	}
	else
		ft_putstr(str);
}

static void	if_zero(char *str, t_data *data, char *prefix, int len)
{
	if (data->zero)
	{
		ft_putstr(prefix);
		print_pad(len, '0');
		precision_print(str, data);
	}
	else
	{
		print_pad(len, ' ');
		ft_putstr(prefix);
		precision_print(str, data);
	}
}

int			apply_flags(char *str, t_data *data, char *prefix)
{
	int		len;

	len = data->width - precision_len(str, data) - ft_strlen(prefix);
	data->prefix = ft_strlen(prefix);
	if (len > 0)
	{
		if (data->minus)
		{
			ft_putstr(prefix);
			precision_print(str, data);
			print_pad(len, ' ');
		}
		else
		{
			if_zero(str, data, prefix, len);
		}
		return (data->width);
	}
	ft_putstr(prefix);
	precision_print(str, data);
	return (ft_strlen(prefix) + precision_len(str, data));
}
