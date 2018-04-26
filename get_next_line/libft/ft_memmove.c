/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	int i;

	if (d > s && d < s + n)
	{
		i = (int)n;
		while (i--)
			*((char *)d + i) = *((char *)s + i);
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*((char *)d + i) = *((char *)s + i);
			i++;
		}
	}
	return (d);
}
