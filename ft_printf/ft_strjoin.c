/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 03:18:27 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/05 03:18:30 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	int		a;
	int		b;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	a = ft_strlen((char *)s1);
	b = ft_strlen((char *)s2);
	if (!(t = (char *)(malloc(a + b + 1))))
		return (0);
	t[a + b] = '\0';
	while (i < a)
	{
		t[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < b)
	{
		t[i + a] = s2[i];
		i++;
	}
	return (t);
}
