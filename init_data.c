/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:11:29 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/23 15:11:29 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		color(t_window *window)
{
	window->color = (int**)malloc(sizeof(int*) * 5);
	window->color[4] = NULL;
	window->color[0] = (int*)malloc(sizeof(int) * 3);
	window->color[0][0] = 0x0000005f;
	window->color[0][1] = 0x00ffffff;
	window->color[0][2] = 0x00BF7818;
	window->color[1] = (int*)malloc(sizeof(int) * 3);
	window->color[1][0] = 0x00000000;
	window->color[1][1] = 0x00ffffff;
	window->color[1][2] = 0x0000ff00;
	window->color[2] = (int*)malloc(sizeof(int) * 3);
	window->color[2][0] = 0x007A00E5;
	window->color[2][1] = 0x00E500DC;
	window->color[2][2] = 0x00ffffff;
	window->color[3] = (int*)malloc(sizeof(int) * 3);
	window->color[3][0] = 0x0091481D;
	window->color[3][1] = 0x001EA968;
	window->color[3][2] = 0x00000000;
}

void		init_data_window(t_window *window, t_window **to_render)
{
	color(window);
	window->active_color = 0;
	window->iter = 0;
	window->j_imag = 0;
	window->j_real = 0;
	window->j_toggle = 0;
	window->index = 0;
	window->zoom = 0.4;
	window->offset_x = 0;
	window->offset_y = 0;
	window->thread = (t_thread*)malloc(sizeof(t_thread) * THREAD_COUNT);
	window->to_render = to_render;
	window->building = 0;
}
