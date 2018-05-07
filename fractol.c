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

int		update_image(t_fractol *fractol)
{
	draw_fractal(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	return (0);
}

int		mouse_move(int x, int y, t_fractol *fractol)
{
	double	tempx;
	double	tempy;

	if (fractol->fractal_id == JULIA)
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
		fractol->zoom *= (1 - ZOOM_SPEED);
	else if (button == scroll_up)
		fractol->zoom *= (1 + ZOOM_SPEED);
	update_image(fractol);

	return (0);
}

void	init_fractol(t_fractol *fractol)
{
	ft_bzero(fractol, sizeof(t_fractol));
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, SIZE, SIZE, "42");
	fractol->img = mlx_new_image(fractol->mlx, SIZE, SIZE);
	fractol->line_size = SIZE * 4;
	fractol->endian = 0;
	fractol->bits_per_pixel = 32;
	fractol->max_iterations = DEFAULT_ITERATIONS;
	fractol->zoom = 0.2;
	fractol->img_addr = mlx_get_data_addr(fractol->img,
		&(fractol->bits_per_pixel), &(fractol->line_size), &(fractol->endian));
	fractol->julia.x = 0.285;
	fractol->julia.y = 0.01;
	fractol->fractal_id = JULIA;
}

int		main(int argc, char *argv[])
{
	t_fractol	fractol;

	init_fractol(&fractol);
	mlx_expose_hook(fractol.win, update_image, &fractol);
	mlx_mouse_hook(fractol.win, mouse_scroll, &fractol);
	mlx_hook(fractol.win, 6, 1L<<6, mouse_move, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
