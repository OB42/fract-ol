/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		input(int key, t_fractol *fractol)
{
	if (esc == key)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		mlx_destroy_image(fractol->mlx, fractol->img);
		exit(0);
	}
	else if (left == key || right == key || down == key || up == key)
	{
		fractol->pos.x += ((left == key) - (right == key)) * POS_INCREMENT;
		fractol->pos.y += ((up == key) - (down == key)) * POS_INCREMENT;
		update_image(fractol);
	}
	else if (fractol->fract_id == BURNING_SHIP && SHIP_SHORTCUT == key)
	{
		fractol->pos.x = 15.5;
		fractol->pos.y = 1;
		fractol->zoom = 0.2325;
		update_image(fractol);
	}
	return (0);
}

int		mouse_move(int x, int y, t_fractol *fractol)
{
	double	tempx;
	double	tempy;

	if (fractol->fract_id == JULIA)
	{
		tempx = (double)x / SIZE * 4 - 2;
		tempy = (double)y / SIZE * 4 - 2;
		if (fabs(fractol->julia.x - tempx) > MIN_JULIA_DIFF
		|| fabs(fractol->julia.y - tempy) > MIN_JULIA_DIFF)
		{
			fractol->julia.x = tempx;
			fractol->julia.y = tempy;
			update_image(fractol);
		}
	}
	return (0);
}

int		mouse_scroll(int button, int x, int y, t_fractol *fractol)
{
	if (button == scroll_down)
		fractol->zoom *= (1 - SPEED);
	else if (button == scroll_up)
		fractol->zoom *= (1 + SPEED);
	update_image(fractol);
	return (0);
}

void	init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, SIZE, SIZE, "42");
	fractol->img = mlx_new_image(fractol->mlx, SIZE, SIZE);
	fractol->line_size = SIZE * 4;
	fractol->endian = 0;
	fractol->bits_per_pixel = 32;
	fractol->max_iterations = DEFAULT_ITERATIONS;
	fractol->zoom = 4;
	fractol->pos.y = 1;
	fractol->pos.x = 1;
	fractol->img_addr = mlx_get_data_addr(fractol->img,
		&(fractol->bits_per_pixel), &(fractol->line_size), &(fractol->endian));
	fractol->julia.x = 0.285;
	fractol->julia.y = 0.01;
}

int		main(int argc, char *argv[])
{
	t_fractol	fractol;

	ft_bzero(&fractol, sizeof(t_fractol));
	if (argc != 2)
		print_error(ERR_USAGE);
	else if ((fractol.fract_id = pr_atoi(argv[1])) < 0
	|| fractol.fract_id >= NB_FRACTAL)
		print_error(ERR_USAGE);
	init_fractol(&fractol);
	mlx_expose_hook(fractol.win, update_image, &fractol);
	mlx_mouse_hook(fractol.win, mouse_scroll, &fractol);
	mlx_hook(fractol.win, 6, 1L << 6, mouse_move, &fractol);
	mlx_key_hook(fractol.win, input, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
