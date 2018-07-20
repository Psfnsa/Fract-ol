/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:09:29 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/24 16:09:30 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	triggers(t_window *window)
{
	mlx_hook(window->win, 4, 0, event_mouse_down, window);
	mlx_hook(window->win, 6, 0, event_mouse_move, window);
	mlx_hook(window->win, 2, 0, event_keyboard, window);
}

int		event_keyboard(int keycode, t_window *window)
{
	if (!window->building)
	{
		if (keycode == KEY_ESCAPE)
			exit(0);
		else if (keycode == KEY_C)
			window->active_color = (window->color[window->active_color +
				1]) ? window->active_color + 1 : 0;
		else if (keycode == NUM_PLUS || keycode == NUM_MINUS)
			window->iter += (keycode == NUM_PLUS) ? 1 : -1;
		else if (keycode == NUM_8 || keycode == ARROW_UP || keycode == KEY_W)
			window->offset_y -= 0.01 / window->zoom;
		else if (keycode == NUM_2 || keycode == ARROW_DOWN || keycode == KEY_S)
			window->offset_y += 0.01 / window->zoom;
		else if (keycode == NUM_4 || keycode == ARROW_LEFT || keycode == KEY_A)
			window->offset_x -= 0.01 / window->zoom;
		else if (keycode == NUM_6 || keycode == ARROW_RIGHT || keycode == KEY_D)
			window->offset_x += 0.01 / window->zoom;
		else if (keycode == KEY_SPACE)
			window->j_toggle = !window->j_toggle;
		window->building = 1;
		build_fractal(window);
	}
	*window->to_render = window;
	return (0);
}

int		event_mouse_move(int mouse_x, int mouse_y, t_window *window)
{
	if (window->j_toggle)
	{
		if (mouse_x <= WIDTH / 2)
			window->j_real = -0.2 * ((WIDTH / 2 - (double)mouse_x) / WIDTH / 2);
		else if (mouse_x > WIDTH / 2)
			window->j_real = 0.2 * (((double)mouse_x - WIDTH / 2) / WIDTH / 2);
		if (mouse_y <= HEIGHT / 2)
			window->j_imag = 0.2 * ((HEIGHT / 2 - (double)mouse_y) /
																	HEIGHT / 2);
		else if (mouse_y > HEIGHT / 2)
			window->j_imag = -0.2 * (((double)mouse_y - HEIGHT / 2) /
																	HEIGHT / 2);
		build_fractal(window);
	}
	*window->to_render = window;
	return (0);
}

int		event_mouse_down(int keycode, int mouse_x, int mouse_y, t_window *win)
{
	double	zoom;
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;

	if ((keycode == 4 || keycode == 5) && !win->building)
	{
		zoom = win->zoom;
		if (keycode == 4)
			win->zoom *= 1.07213535211;
		else if (keycode == 5)
			win->zoom /= 1.07213535211;
		old_x = mouse_x - (WIDTH / 2);
		old_y = mouse_y - (HEIGHT / 2);
		new_x = old_x * (win->zoom / zoom);
		new_y = old_y * (win->zoom / zoom);
		win->offset_x += ((new_x - old_x)) / WIDTH / win->zoom;
		win->offset_y += ((new_y - old_y)) / HEIGHT / win->zoom;
		build_fractal(win);
	}
	*win->to_render = win;
	return (0);
}
