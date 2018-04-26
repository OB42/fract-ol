/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:06:05 by obenazzo          #+#    #+#             */
/*   Updated: 2017/12/22 16:50:48 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	get_dioux(va_list args, t_fspec spec)
{
	long long	n;

	n = (((spec.sub < 1 || SUBZ[spec.sub - 1] <= sizeof(int)) &&
	!ft_strchr("DO", spec.s)) ? va_arg(args, int) : va_arg(args, long long));
	if (spec.sub == -1 && !ft_strchr("DO", spec.s))
		UCAST(int);
	else if (spec.sub == 0 && !ft_strchr("DO", spec.s))
		UCAST(char);
	else if (spec.sub == 1)
		UCAST(long long);
	else if (spec.sub == 2)
		UCAST(short);
	else if (spec.sub == 3)
		UCAST(long);
	else if (spec.sub == 4)
		n = (ft_strchr("dDi", spec.s) ? ((intmax_t)n) : ((uintmax_t)n));
	else if (spec.sub == 5)
		n = (size_t)n;
	return (n);
}

int			get_next_arg(va_list args, t_fspec *spec, void **t)
{
	if (ft_strchr("sS", spec->s))
		*t = va_arg(args, void *);
	else if (spec->s == 'p')
		*t = ft_ulltoa_base((ULL)va_arg(args, void *), 16, 0);
	else if (spec->s == 'U')
		*t = ft_ulltoa_base(va_arg(args, ULL), 10, 0);
	else if (ft_strchr("oOuxX", spec->s))
		*t = (ft_ulltoa_base(get_dioux(args, *spec),
		SPECS_BASE[ft_indexof("oux", ft_tolower(spec->s))], spec->s == 'X'));
	else if (ft_strchr("dDi", spec->s))
		*t = ft_lltoa(get_dioux(args, *spec));
	else if ((*t = malloc(2 * (spec->s != 'C' ? 1 : sizeof(wint_t)))))
	{
		if (!ft_strchr("Cc", spec->s))
			((char *)*t)[0] = spec->s;
		else if (spec->s == 'C')
			((wchar_t *)*t)[0] = va_arg(args, wint_t);
		else
			((char *)*t)[0] = spec->s == 'c' ? va_arg(args, int) : '%';
		(spec->s != 'C' ? (((char *)*t)[1] = 0)
		: (((wchar_t *)*t)[1] = 0));
	}
	else
		return (0);
	return (1);
}
