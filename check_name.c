/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:26:27 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/23 17:26:28 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_name1(t_data2 *data, char *name, int i, t_window **to_render)
{
	if (ft_strncomplex("julia", name, 5))
	{
		data->window[i - 1].build = build_julia;
		init_window(data->mlx, &data->window[i - 1], name, to_render);
		return (0);
	}
	else if (ft_strncomplex("flowerbrot", name, 10))
	{
		data->window[i - 1].build = build_flowerbrot;
		init_window(data->mlx, &data->window[i - 1], name, to_render);
		return (0);
	}
	else if (ft_strncomplex("burningship", name, 11))
	{
		data->window[i - 1].build = build_burningship;
		init_window(data->mlx, &data->window[i - 1], name, to_render);
		return (0);
	}
	return (check_name2(data, name, i, to_render));
}

int		check_name2(t_data2 *data, char *name, int i, t_window **to_render)
{
	if (ft_strncomplex("mandelbar", name, 9))
	{
		data->window[i - 1].build = build_mandelbar;
		init_window(data->mlx, &data->window[i - 1], name, to_render);
		return (0);
	}
	else if (ft_strncomplex("mandelbrot", name, 10))
	{
		data->window[i - 1].build = build_mandelbrot;
		init_window(data->mlx, &data->window[i - 1], name, to_render);
		return (0);
	}
	else
	{
		ft_printf("Incorrect Fractal Name\n~~Try this Fractals:~~\n");
		ft_printf("1)Julia\n2)FlowerBrot\n3)BurningShip\n4)MandelBar\n");
		ft_printf("5)MandelBrot\n(NOTCASESENSITIVE)\n");
		exit(0);
	}
}
