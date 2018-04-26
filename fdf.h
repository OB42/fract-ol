/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "math.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define ERR_NBR_PARSING		"Invalid character after a number\n"
# define ERR_USAGE				"Usage: ./fdf <map.fdf>\n"
# define ERR_FILE_READING 		"Can't read source file\n"
# define ERR_MALLOC				"malloc error\n"
# define ERR_PARSING			"Parsing error\n"
# define ERR_GNL				"GNL error\n"
# define ANGLE_INCREMENT 10
# define POS_INCREMENT 25
# define WIDTH 1024
# define HEIGHT 1024

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
typedef struct		s_v
{
	double			x;
	double			y;
	double			z;
}					t_v;

typedef struct		s_fdf
{
	t_v				**map;
	t_p				dim;
	t_v				ang;
	double			zoom;
	t_p				pos;
	void			*win;
	void			*mlx;
	void			*img;
}					t_fdf;

void				draw_line(t_v a, t_v b, t_fdf *fdf);
t_v					rot(t_v v, t_v a);
t_p					get_map(char *file, int fd, t_v ***map);
void				*pr_malloc(size_t n);
void				pr_free(void *p);
void				print_error(char *err);
char				**while_char(char *str, char **words, int save, int w);
char				**w_char(char *str, char **words, int save, int w);
char				**split(char *str);
int					pr_atoi(const char *str);
void				check_nbr_parsing(char c);
#endif
