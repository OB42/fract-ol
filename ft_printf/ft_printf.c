/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:06:05 by obenazzo          #+#    #+#             */
/*   Updated: 2017/12/22 16:50:48 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		get_prev(t_fspec spec, void **str, char *prev)
{
	if (ft_strchr("sScCu", spec.s))
		prev[0] = 0;
	else if (((char *)(*str))[0] == '-')
	{
		ft_strcpy(prev, "-");
		(*str)++;
	}
	else if (spec.s == 'p' || (ft_strchr("oOxX", spec.s) && spec.f[0]
	&& ((char *)*str)[0] != '0'))
		ft_strcpy(prev, PREC[ft_indexof("poOxX", spec.s)]);
	else if ((spec.f[3] || spec.f[4]) && ft_strchr("dDi", spec.s)
	&& ft_isdigit(((char *)*str)[0]))
		ft_strcpy(prev, spec.f[3] ? "+" : " ");
	else
		prev[0] = 0;
}

void		*put_arg(t_fspec spec, void *str, int *printed)
{
	char	prev[3];
	size_t	(*f_len)(const void *);
	size_t	len;

	(spec.p || (spec.f[0] && ft_strchr("oO", spec.s))) ?
	get_prev(spec, &str, prev) : (prev[0] = 0);
	f_len = (ft_strchr("SC", spec.s) ? (&ft_wcslen) : (&ft_voidstrlen));
	len = (ft_strchr("cC", spec.s) && !((char *)str)[0]) ? 1 : f_len(str);
	spec.s = (ft_strchr("cC", spec.s) && !((char *)str)[0]) ? 'c' : spec.s;
	if (spec.f[1])
		ft_write_count(prev, ft_strlen(prev), printed, 0);
	if (!spec.f[2] && spec.w != -1)
		padding(spec.f[1] && !spec.f[2], spec.w - (((ft_strchr("sS", spec.s) &&
		spec.p != -1) ? &sml : &big)(len, spec.p) + ft_strlen(prev)), printed);
	if (!spec.f[1])
		ft_write_count(prev, ft_strlen(prev), printed, 0);
	if (ft_strchr("dDioOuUxX", spec.s) && spec.p != -1 && (UI)spec.p > len)
		padding(1, spec.p - len - (ft_strchr("oO", spec.s) ?
		ft_strlen(prev) : 0), printed);
	ft_write_count(str, (ft_strchr("sS", spec.s) && spec.p != -1 &&
	(UI)spec.p < len) ? spec.p : len, printed, !!ft_strchr("SC", spec.s));
	if (spec.f[2] && spec.w != -1)
		padding(spec.f[1] && !spec.f[2], spec.w - (((ft_strchr("sS", spec.s) &&
		spec.p != -1) ? &sml : &big)(len, spec.p) + ft_strlen(prev)), printed);
	return (str);
}

int			print(va_list args, const char *s, int *printed)
{
	void	*t;
	char	*sub[SUB_SPECS_LEN];
	char	*f;
	t_fspec	spec;

	ft_memcpy(sub, SUB_SPECS, sizeof(sub));
	spec = (t_fspec){{0, 0, 0, 0, 0}, -1, -1, -1, 0};
	f = ft_strchr(s, '%');
	ft_write_count(s, f ? (f - s) : ft_strlen(s), printed, 0);
	if (!f || !(*(f++)) || !(f = parse_specifier(&spec, f, sub, args)))
		return (1);
	if (!(get_next_arg(args, &spec, &t)))
		return (0);
	if (t)
		put_arg(spec, (ft_strchr("dDioOuUxX", spec.s) && !spec.p)
		&& ((char *)t)[0] == '0' ? "" : t, printed);
	else
	{
		spec.s = (spec.s == 'S' ? 's' : spec.s);
		put_arg(spec, "(null)", printed);
	}
	if (t && !ft_strchr("sS", spec.s))
		free(t);
	return (*f ? print(args, f, printed) : 1);
}

int			ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, s);
	if (!print(args, s, &ret))
		ret = -1;
	va_end(args);
	return (ret);
}
