/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 03:18:27 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/05 03:18:30 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int c;

	c = 0;
	while (src[c])
	{
		dest[c] = src[c];
		c++;
	}
	dest[c++] = '\0';
	return (dest);
}
