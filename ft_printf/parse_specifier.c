/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:06:05 by obenazzo          #+#    #+#             */
/*   Updated: 2017/12/22 16:50:48 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*parse_specifier(t_fspec *spec, char *f, char **sub, va_list args)
{
	int i;

	i = 0;
	while (*f && ft_strchr(FLAGS, *f))
		spec->f[ft_indexof(FLAGS, *(f++))] = 1;
	if (*f && (*f == '*' || ft_isdigit(*f)))
		spec->w = (*(f++) == '*' ? va_arg(args, int) : ft_atoi(f - 1));
	if (*ft_skip_digits(&f) && *f == '.')
		spec->p = (*(f + 1) == '*' ? va_arg(args, int) : ft_atoi(f += 1));
	if (*ft_skip_digits(&f) && ft_strchr("hljz", *f))
	{
		while (i++ < SUB_SPECS_LEN && spec->sub < 0)
		{
			if (!ft_strncmp(sub[i - 1], f, ft_strlen(sub[i - 1])))
				spec->sub = i - 1;
		}
		f += ft_strlen(sub[spec->sub]);
	}
	if (!(spec->s = *(f++)))
		return (0);
	if (spec->sub == 3 && ft_strchr("sc", spec->s))
		spec->s = ft_toupper(spec->s);
	spec->f[1] = (spec->p != -1 ? 0 : spec->f[1]);
	return (f);
}
