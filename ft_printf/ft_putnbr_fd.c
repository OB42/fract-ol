/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	putnb(long long nbr, int fd)
{
	if (nbr >= 10)
	{
		putnb(nbr / 10, fd);
		putnb(nbr % 10, fd);
	}
	else
		ft_putchar_fd('0' + nbr, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	long long	val;

	val = n;
	if (val < 0)
	{
		ft_putchar_fd('-', fd);
		val = -val;
	}
	putnb(val, fd);
}
