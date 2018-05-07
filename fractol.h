/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "math.h"
# include "ft_printf/ft_printf.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define ERR_USAGE				"Usage: ./fractol [fractal_id: 0-2]\n"
# define ERR_MALLOC				"malloc error\n"
# define ERR_NBR_PARSING	"Invalid character after a number\n"
# define POS_INCREMENT 0.25
# define SIZE 1024
# define DEFAULT_ITERATIONS 100
# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2
# define NB_FRACTAL 3
# define SPEED 0.1
# define MIN_JULIA_DIFF 21.0f / SIZE

typedef struct		s_p
{
	double			x;
	double			y;
}					t_p;

enum	e_keys {
	k1 = 0x12,
	k2 = 0x13,
	k3 = 0x14,
	k4 = 0x15,
	k6 = 0x16,
	k5 = 0x17,
	k9 = 0x19,
	k7 = 0x1A,
	k8 = 0x1C,
	k0 = 0x1D,
	plus = 0x45,
	minus = 0x4E,
	up = 0x7E,
	down = 0x7D,
	left = 0x7B,
	right = 0x7C,
	esc = 0x35
};

# define SHIP_SHORTCUT k1

enum	e_mouse {
	scroll_down = 0x4,
	scroll_up = 0x5
};

typedef struct		s_fractol
{
	t_p				pos;
	t_p				julia;
	void			*win;
	void			*mlx;
	void			*img;
	char			*img_addr;
	int				line_size;
	int				endian;
	int				bits_per_pixel;
	int				max_iter;
	int				fract_id;
	float			zoom;
}					t_fractol;

void				*pr_malloc(size_t n);
void				pr_free(void *p);
void				print_error(char *err);
void				draw_fractal(t_fractol *fractol);
int					update_image(t_fractol *fractol);
int					pr_atoi(const char *str);
#endif
