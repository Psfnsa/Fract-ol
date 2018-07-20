/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:44:20 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/22 18:44:22 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	build_fractal(t_window *window)
{
	int	j;

	j = -1;
	while (++j < THREAD_COUNT)
		pthread_create(&window->thread[j].t_id, NULL,
							window->build, &window->thread[j]);
	j = -1;
	while (++j < THREAD_COUNT)
		pthread_join(window->thread[j].t_id, NULL);
}

int		render(t_data2 *data)
{
	if (data->to_render)
	{
		mlx_put_image_to_window(data->mlx, data->to_render->win,
								data->to_render->img, 0, 0);
		data->to_render->building = 0;
	}
	return (0);
}

void	init_window(void *mlx, t_window *window, char *name, t_window **to_rend)
{
	int		bpp;
	int		ppl;
	int		end;
	int		j;

	bpp = 32;
	ppl = WIDTH;
	end = 0;
	window->win = mlx_new_window(mlx, WIDTH, HEIGHT, name);
	window->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	window->pixel = (int*)mlx_get_data_addr(window->img, &bpp, &ppl, &end);
	triggers(window);
	init_data_window(window, to_rend);
	j = -1;
	while (++j < THREAD_COUNT)
	{
		window->thread[j].window = window;
		window->thread[j].start = j * LPT;
		pthread_create(&window->thread[j].t_id, NULL,
							window->build, &window->thread[j]);
	}
	j = -1;
	while (++j < THREAD_COUNT)
		pthread_join(window->thread[j].t_id, NULL);
	mlx_put_image_to_window(mlx, window->win, window->img, 0, 0);
}

int		main(int ac, char **av)
{
	t_data2	data;
	int		i;
	int		j;

	i = 0;
	data.win_count = ac - 1;
	data.mlx = mlx_init();
	data.to_render = NULL;
	data.window = (t_window*)malloc(sizeof(t_window) * (ac - 1));
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			av[i][j] = ft_tolower(av[i][j]);
		check_name1(&data, av[i], i, &data.to_render);
	}
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
}
