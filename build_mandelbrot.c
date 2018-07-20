/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:51:01 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/23 16:51:02 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate(t_thread *thr, int x, int y)
{
	t_complex	p;
	t_complex	n;
	t_complex	o;
	int			i;

	p.r = 1.5 * ((x - WIDTH / 2) / (thr->window->zoom * WIDTH) +
												thr->window->offset_x) - 0.6;
	p.i = (y - HEIGHT / 2) / (thr->window->zoom * HEIGHT) +
												thr->window->offset_y;
	n.r = 0;
	n.i = 0;
	i = -1;
	while (++i < thr->window->iter && n.r * n.r + n.i * n.i <= 4)
	{
		o.r = n.r;
		o.i = n.i;
		n.r = o.r * o.r - o.i * o.i + p.r;
		n.i = 2 * o.r * o.i + p.i;
	}
	thr->window->pixel[x + y * WIDTH] =
		set_color(thr->window->color[thr->window->active_color],
					(float)i / thr->window->iter + !(i < thr->window->iter));
}

void		*build_mandelbrot(void *thread)
{
	t_thread	*thr;
	int			y;
	int			x;

	thr = (t_thread*)thread;
	y = thr->start;
	while (y < HEIGHT && y < thr->start + LPT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			calculate(thr, x, y);
		}
		y++;
	}
	return (NULL);
}
