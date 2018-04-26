/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		digits(int n)
{
	int	d;

	d = 1;
	n = n < 0 ? -n : n;
	while (n >= 10)
	{
		d++;
		n /= 10;
	}
	return (d);
}

static	void	putnb(long long nbr, char **s)
{
	if (nbr >= 10)
	{
		putnb(nbr / 10, s);
		putnb(nbr % 10, s);
	}
	else
	{
		**s = '0' + nbr;
		(*s)++;
	}
}

char			*ft_itoa(int value)
{
	long long	kek;
	int			l;
	char		*a;
	char		**s;
	char		*b;

	kek = value;
	l = digits(value);
	a = (char *)malloc(l + (kek < 0 ? 2 : 1));
	if (!a)
		return (0);
	b = a;
	s = &a;
	if (kek < 0)
	{
		**s = '-';
		(*s)++;
		kek = -kek;
	}
	putnb(kek, s);
	**s = 0;
	(*s)++;
	return (b);
}
