/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 06:42:34 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/12 06:42:35 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		l(long long n)
{
	int	d;

	if (n + 1 == -9223372036854775807)
		return (21);
	d = 2;
	n = n < 0 ? -n : n;
	while (n >= 10)
	{
		d++;
		n /= 10;
	}
	return (d);
}

static	void	putnb(unsigned long long nbr, char **s, int caps)
{
	if (nbr >= 10)
	{
		putnb(nbr / 10, s, 10);
		putnb(nbr % 10, s, 10);
	}
	else
	{
		**s = '0' + nbr;
		(*s)++;
	}
}

char			*ft_lltofcuka(long long value)
{
	char		*a;
	char		**s;
	char		*b;

	if (!(a = (char *)malloc(l(value))))
		return (0);
	if (value + 1 == -9223372036854775807)
	{
		ft_memcpy(a, "-9223372036854775808", 20);
		return (a);
	}
	b = a;
	s = &a;
	if (value < 0)
	{
		*((*s)++) = '-';
		value = -value;
	}
	putnb(value, s, 1);
	*((*s)++) = 0;
	return (b);
}
