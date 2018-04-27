/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_y(t_v *a, t_v *b, t_fdf *fdf)
{
	double	y;
	double	p;

	y = -1;
	p = (b->x - a->x) / (b->y - a->y);
	while (a->y + y++ < b->y)
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->pos.x + p * y + a->x + 0.5,
			fdf->pos.y + a->y + y, 0x00babc);
}

void	bresenham(t_v *a, t_v *b, t_fdf *fdf)
{
	double	x;
	double	p;

	x = -1;
	p = (b->y - a->y) / (b->x - a->x);
	while (a->x + x++ < b->x)
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->pos.x + a->x + x,
			fdf->pos.y + p * x + a->y + 0.5, 0x00babc);
}

void	draw_line(t_v a, t_v b, t_fdf *fdf)
{
	a = rot((t_v){a.x * fdf->zoom, a.y * fdf->zoom, a.z * fdf->zoom * 0.5}, fdf->ang);
	b = rot((t_v){b.x * fdf->zoom, b.y * fdf->zoom, b.z * fdf->zoom * 0.5}, fdf->ang);
	if (fabs(a.x - b.x) > fabs(a.y - b.y))
		return ((a.x < b.x ? bresenham(&a, &b, fdf)
		: bresenham(&b, &a, fdf)));
	else
		return ((a.y < b.y ? bresenham_y(&a, &b, fdf)
		: bresenham_y(&b, &a, fdf)));
}
