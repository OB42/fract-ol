/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 05:40:46 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/07 06:16:06 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		s;
	char	*temp;

	s = ft_strlen(src);
	temp = (char*)malloc(s + 1);
	if (!temp)
		return (0);
	temp[s] = '\0';
	while (s--)
		temp[s] = src[s];
	return (temp);
}
