/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:34:49 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/05 22:46:04 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dl;
	size_t	sl;
	int		s;

	dl = ft_strlen(dest);
	sl = ft_strlen((char *)src);
	if (size < dl)
		return (size + sl);
	dest += dl;
	s = 0;
	while (src[s] && s < (int)(size - dl - 1))
		*dest++ = src[s++];
	if (size && dl <= size)
		*dest = 0;
	return (dl + sl);
}
