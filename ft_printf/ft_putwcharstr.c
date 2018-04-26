/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwcharstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:06:05 by obenazzo          #+#    #+#             */
/*   Updated: 2017/12/22 16:50:48 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_putwchar(wchar_t c, int *printed)
{
	int tw;

	if (c <= 0x7F || (c > 0x10FFFF && MB_CUR_MAX < 4))
		write(1, &c, tw = 1);
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)
	{
		tw = 2;
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)
	{
		tw = 3;
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3f) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else
		write(1, &c, tw = 4);
	*printed += tw;
}

void			ft_putwcharstr(wchar_t *str, int *printed, size_t count)
{
	size_t	i;

	i = 0;
	while (*str && i++ < count)
		ft_putwchar(*(str++), printed);
}
