/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 03:45:00 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/05 03:45:03 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int s;
	int t;

	s = 0;
	if (!to_find[0])
		return ((char *)str);
	if (!str[0])
		return (0);
	while (str[s] != '\0')
	{
		t = 0;
		while (to_find[t] == str[s + t])
		{
			if (to_find[t + 1] == '\0')
			{
				return ((char *)str + s);
			}
			t++;
		}
		s++;
	}
	return (0);
}
