/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:26:02 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/23 15:26:03 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate(t_thread *thr, int x, int y)
{
	t_complex	n;
	t_complex	o;
	int			i;

	n.r = (x - WIDTH / 2) / (thr->window->zoom * WIDTH) +
												thr->window->offset_x;
	n.i = (y - HEIGHT / 2) / (thr->window->zoom * HEIGHT) +
												thr->window->offset_y;
	i = -1;
	while (++i < thr->window->iter && n.r * n.r + n.i * n.i <= 4)
	{
		o.r = n.r;
		o.i = n.i;
		n.r = o.r * o.r - o.i * o.i + (-0.7 + thr->window->j_real);
		n.i = 2 * o.r * o.i + (0.27015 + thr->window->j_imag);
	}
	thr->window->pixel[x + y * WIDTH] =
		set_color(thr->window->color[thr->window->active_color],
					(float)i / thr->window->iter + !(i < thr->window->iter));
}

void		*build_julia(void *thread)
{
	t_thread	*thr;
	int			x;
	int			y;

	thr = (t_thread*)thread;
	y = thr->start;
	while (y < HEIGHT && y < thr->start + LPT)
	{
		x = -1;
		while (++x < WIDTH)
			calculate(thr, x, y);
		y++;
	}
	return (NULL);
}
