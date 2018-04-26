/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:06:05 by obenazzo          #+#    #+#             */
/*   Updated: 2017/12/22 16:50:48 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <wchar.h>
# define FLAGS "#0-+ "
# define PR "poOxX"
# define PREC (char *[]){"0x", "0", "0", "0x", "0X"}
# define SUB_SPECS (char *[]){"hh", "ll", "h", "l", "j", "z"}
# define SUB_SPECS_LEN 6
# define SPECS_BASE (int []){8, 10, 16}
# define UN unsigned
# define UI unsigned int
# define ULL unsigned long long
# define LL long long
# define SZ sizeof
# define UCAST(ty) ft_strchr("di", spec.s) ? (n = (ty)n) : (n = (unsigned ty)n)
# define SUBZ (size_t []){SZ(LL), SZ(short), SZ(long), SZ(intmax_t), SZ(size_t)}
# define M_CAST(type, x) f(x) ? (n = (type)n) : (n = (unsigned type)n)

typedef struct	s_fspec
{
	int		f[5];
	int		w;
	int		p;
	int		sub;
	char	s;
}				t_fspec;

char			*parse_specifier(t_fspec *s, char *f, char **sub, va_list args);
int				padding(int zero, int l, int *printed);
int				get_next_arg(va_list args, t_fspec *spec, void **t);
int				ft_printf(const char *format, ...);
#endif
