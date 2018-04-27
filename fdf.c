/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		print_map(t_fdf *fdf)
{
	int	x;
	int	y;

	mlx_clear_window(fdf->mlx, fdf->win);
	x = 0;
	y = 0;
	while (x < (int)fdf->dim.x)
	{
		y = 0;
		while (y < (int)fdf->dim.y)
		{
			if (x + 1 < (int)fdf->dim.x)
				draw_line(fdf->map[x][y], fdf->map[x + 1][y], fdf);
			if (y + 1 < (int)fdf->dim.y)
				draw_line(fdf->map[x][y], fdf->map[x][y + 1], fdf);
			y++;
		}
		x++;
	}
	return (0);
}

t_v		rot(t_v v, t_v a)
{
	if (a.x != 0.0)
	{
		v.y = v.y * cos(a.x) - v.z * sin(a.x);
		v.z = v.y * sin(a.x) + v.z * cos(a.x);
	}
	if (a.y != 0.0)
	{
		v.z = v.z * cos(a.y) - v.x * sin(a.y);
		v.x = v.z * sin(a.y) + v.x * cos(a.y);
	}
	if (a.z != 0.0)
	{
		v.x = v.x * cos(a.z) - v.y * sin(a.z);
		v.y = v.x * sin(a.z) + v.y * cos(a.z);
	}
	return (v);
}

void	free_fdf(t_fdf *fdf)
{
	int i;

	i = 0;
	mlx_destroy_window(fdf->mlx, fdf->win);
	while (i < fdf->dim.x)
		pr_free(fdf->map[i++]);
	pr_free(fdf->map);
	exit(0);
}

int		input(int key, t_fdf *fdf)
{
	if (esc == key)
		free_fdf(fdf);
	else if (k1 == key)
		fdf->ang.x += ANGLE_INCREMENT * M_PI / 180;
	else if (k2 == key)
		fdf->ang.x -= ANGLE_INCREMENT * M_PI / 180;
	else if (k3 == key)
		fdf->ang.y += ANGLE_INCREMENT * M_PI / 180;
	else if (k4 == key)
		fdf->ang.y -= ANGLE_INCREMENT * M_PI / 180;
	else if (k5 == key)
		fdf->ang.z += ANGLE_INCREMENT * M_PI / 180;
	else if (k6 == key)
		fdf->ang.z -= ANGLE_INCREMENT * M_PI / 180;
	else if (plus == key || minus == key)
		fdf->zoom += ((plus == key) - (minus == key)) * 1.1;
	else if (left == key || right == key)
		fdf->pos.x += ((right == key) - (left == key)) * POS_INCREMENT;
	else if (down == key || up == key)
		fdf->pos.y += ((down == key) - (up == key)) * POS_INCREMENT;
	print_map(fdf);
	return (0);
}

int		main(int argc, char *argv[])
{
	int			input_fd;
	t_fdf		fdf;

	if (argc != 2)
		print_error(ERR_USAGE);
	if ((input_fd = open(argv[1], O_RDONLY, S_IRUSR)) == -1)
		print_error(ERR_FILE_READING);
	ft_bzero(&fdf, sizeof(t_fdf));
	fdf.dim = get_map(argv[1], input_fd, &(fdf.map));
	fdf.mlx = mlx_init();
	fdf.ang.x = 20 * M_PI / 180;
	fdf.ang.y = 20 * M_PI / 180;
	fdf.ang.z = 20 * M_PI / 180;
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "42");
	fdf.zoom = (fdf.dim.x / fdf.dim.y > HEIGHT / WIDTH) ?
					(HEIGHT / fdf.dim.x * 0.8) : (WIDTH / fdf.dim.y * 0.8);
	fdf.pos.y = 0.1 * WIDTH;
	fdf.pos.x = 0.1 * HEIGHT;
	mlx_expose_hook(fdf.win, print_map, &fdf);
	mlx_key_hook(fdf.win, input, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
