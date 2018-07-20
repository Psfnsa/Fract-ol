/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_flowerbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:45:35 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/23 15:45:36 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate(t_thread *thr, int x, int y)
{
	t_complex	p;
	t_complex	n;
	double		t;
	int			i;

	p.r = (x - WIDTH / 2) / (thr->window->zoom * WIDTH) +
												thr->window->offset_x;
	p.i = (y - HEIGHT / 2) / (thr->window->zoom * HEIGHT) +
												thr->window->offset_y;
	n.r = 0;
	n.i = 0;
	i = -1;
	while (++i < thr->window->iter && pow(n.r, 6) + pow(n.i, 6) < 4)
	{
		t = n.r;
		n.r = pow(n.r, 6) - (15 * pow(n.r, 4) * pow(n.i, 2)) +
						(15 * pow(n.r, 2) * pow(n.i, 4)) - pow(n.i, 6) + p.i;
		n.i = (6 * pow(t, 5) * n.i - 20 * pow(t, 3) * pow(n.i, 3) +
												6 * t * pow(n.i, 5)) + p.r;
	}
	thr->window->pixel[x + y * WIDTH] =
		set_color(thr->window->color[thr->window->active_color],
					(float)i / thr->window->iter + !(i < thr->window->iter));
}

void		*build_flowerbrot(void *thread)
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
