/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmemcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *a, const void *b, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n)
	{
		if (*(char *)(a + i) - *(char *)(b + i))
			return (*(unsigned char *)(a + i) - *(unsigned char *)(b + i));
		i++;
	}
	return (0);
}
