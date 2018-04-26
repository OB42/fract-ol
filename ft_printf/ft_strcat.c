/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:34:49 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/05 22:18:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int d;
	int s;

	d = 0;
	s = 0;
	while (dest[d] != '\0')
		d++;
	while (src[s] != '\0')
	{
		dest[d + s] = src[s];
		s++;
	}
	dest[d + s] = '\0';
	return (dest);
}
