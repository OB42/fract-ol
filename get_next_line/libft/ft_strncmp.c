/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 04:30:43 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/06 10:52:11 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && i < n && (!i || (a[i - 1] && b[i - 1])))
	{
		if (*(unsigned char *)(a + i) - *(unsigned char *)(b + i))
			return (*(unsigned char *)(a + i) - *(unsigned char *)(b + i));
		i++;
	}
	return (0);
}
