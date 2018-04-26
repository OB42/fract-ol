/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*t;

	if (!s || !f)
		return (0);
	i = 0;
	t = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!t)
		return (0);
	while (s[i])
	{
		t[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	t[i] = 0;
	return (t);
}
