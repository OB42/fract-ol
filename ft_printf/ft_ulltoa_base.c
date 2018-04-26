/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 06:42:34 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/12 06:42:35 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		udigits_base(unsigned long long n, int base)
{
	int	d;

	d = 1;
	while (n >= (unsigned int)base)
	{
		d++;
		n /= base;
	}
	return (d);
}

static	void	putnb(unsigned long long nbr, char **s, int base, int uppercase)
{
	static char hex[16] = "0123456789ABCDEF";

	if (nbr >= (unsigned int)base)
	{
		putnb(nbr / base, s, base, uppercase);
		putnb(nbr % base, s, base, uppercase);
	}
	else
		*((*s)++) = uppercase ? hex[nbr] : ft_tolower(hex[nbr]);
}

char			*ft_ulltoa_base(unsigned long long n, int base, int uppercase)
{
	int			l;
	char		*a;
	char		**s;
	char		*b;

	l = udigits_base(n, base);
	if (!(a = (char *)malloc(l + 1)))
		return (0);
	b = a;
	s = &a;
	putnb(n, s, base, uppercase);
	*((*s)++) = 0;
	return (b);
}
