/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *d, int c)
{
	int i;
	int n;

	i = 0;
	n = ft_strlen(d);
	if (!n && c)
		return (NULL);
	while (i <= n)
	{
		if ((char)c == (char)(d[i]))
			return ((char *)(d + i));
		i++;
	}
	return (NULL);
}
