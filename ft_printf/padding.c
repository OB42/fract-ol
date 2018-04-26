/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:06:05 by obenazzo          #+#    #+#             */
/*   Updated: 2017/12/22 16:50:48 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			padding(int zero, int l, int *printed)
{
	char	*a;

	if (l < 1 || !(a = ft_ntchar(l, zero ? '0' : ' ')))
		return (0);
	ft_write_count(a, l, printed, 0);
	free(a);
	return (1);
}
