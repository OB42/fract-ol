/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pixel(t_p *p, int color, t_fractol *fractol)
{
	if (p->x < SIZE && p->y < SIZE && p->y >= 0 && p->x >=0)
		*(int *)(fractol->img_addr + ((int)(p->y * SIZE + p->x) * 4)) =
		mlx_get_color_value(fractol->mlx, color);
}

int		get_iteration_color(int iterations)
{
	static int colors[16] = {
		0x421e0f,
		0x19071a,
		0x09012f,
		0x040449,
		0x000764,
		0x0c2c8a,
		0x1852b1,
		0x397dd1,
		0x86b5e5,
		0xd3ecf8,
		0xf1e9bf,
		0xf8c95f,
		0xffaa00,
		0xcc8000,
		0x995700,
		0x6a3403
	};

	return (colors[iterations % 16]);
}

int		ft_iterate(t_p p, t_p c, t_fractol *fractol)
{
	static int		n;
	static double	xx;
	static double	yy;

	n = 0;
	while (n < fractol->max_iterations && (xx = p.x * p.x)
	+ (yy = p.y * p.y) < 4.0)
	{
		p.y = 2.0 * p.x * p.y + c.y;
		p.x = xx - yy + c.x;
		n++;
	}
	return (n);
}

void	draw_fractal(t_fractol *fractol)
{
	t_p		pos;
	t_p		pixel;
	int		iterations;
	double	scale;
	double	save;

	ft_memset(fractol->img_addr, 0, fractol->line_size * SIZE);
	pos.x = -fractol->zoom/2;
	pos.y = pos.x;
	save = pos.x;
	pixel.y = -1;
	scale = fractol->zoom / SIZE;
	while (++pixel.y < SIZE)
	{
		pos.x = save;
		pixel.x = -1;
		while (++pixel.x < SIZE)
		{
			iterations = ft_iterate(pos,
				fractol->fractal_id == JULIA ? fractol->julia : pos, fractol);
			if (iterations != fractol->max_iterations)
				set_pixel(&pixel, get_iteration_color(iterations), fractol);
			pos.x += scale;
		}
		pos.y += scale;
	}
}
