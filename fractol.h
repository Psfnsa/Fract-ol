/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:23:16 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/23 15:23:19 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

# define WIDTH 1200
# define HEIGHT 800
# define THREAD_COUNT 20
# define LPT (HEIGHT / THREAD_COUNT)
# define KEY_ESCAPE 53
# define NUM_PLUS 69
# define NUM_MINUS 78
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define NUM_2 84
# define NUM_4 86
# define NUM_6 88
# define NUM_8 91
# define KEY_C 8
# define KEY_SPACE 49

typedef struct s_window	t_window;

typedef struct			s_argb
{
	unsigned char		a;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_argb;

typedef struct			s_complex
{
	double				r;
	double				i;
}						t_complex;

typedef struct			s_thread
{
	pthread_t			t_id;
	int					start;
	t_window			*window;
}						t_thread;

struct					s_window
{
	struct s_window		**to_render;
	int					index;
	void				*(*build)(void *);
	void				*win;
	void				*img;
	int					*pixel;
	t_thread			*thread;
	double				zoom;
	double				offset_x;
	double				offset_y;
	double				j_real;
	double				j_imag;
	int					j_toggle;
	int					iter;
	int					building;
	int					**color;
	int					active_color;
};

typedef struct			s_data2
{
	void				*mlx;
	t_window			*window;
	int					win_count;
	t_window			*to_render;
}						t_data2;

void					*build_julia(void *thread);
int						set_color(int *color, float pos);
void					init_data_window(t_window *window,
														t_window **to_render);
void					*build_flowerbrot(void *thread);
void					*build_burningship(void *thread);
int						render(t_data2 *data);
void					init_window(void *mlx, t_window *window, char *name,
														t_window **to_render);
void					*build_mandelbrot(void *thread);
void					*build_mandelbar(void *thread);
int						check_name1(t_data2 *data, char *name, int i,
														t_window **to_render);
int						check_name2(t_data2 *data, char *name, int i,
														t_window **to_render);
void					triggers(t_window *window);
int						event_mouse_move(int mouse_x, int mouse_y,
															t_window *window);
int						event_keyboard(int keycode, t_window *window);
void					build_fractal(t_window *window);
int						event_mouse_down(int keycode, int mouse_x, int mouse_y,
																t_window *win);
void					color(t_window *window);

#endif
