/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *d, int c)
{
	int i;
	int n;

	n = ft_strlen(d);
	if (!n && c)
		return (NULL);
	i = n;
	while (i > -1)
	{
		if ((char)c == (char)(d[i]))
			return ((char *)(d + i));
		i--;
	}
	return (NULL);
}
