/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	get_strs(char const *s, char **a, char c)
{
	int		i;
	int		r;
	int		y;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (s[i] != c && (!i || s[i - 1] == c))
		{
			y = 0;
			while (s[y + i] != c && y + i < (int)ft_strlen(s))
				y++;
			if (!(a[r] = (char *)malloc(y + 1)))
				return (0);
			ft_strncpy(a[r], (char *)(s + i), y);
			a[r++][y] = 0;
		}
		i++;
	}
	a[r] = 0;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		r;
	char	**a;

	if (!s)
		return (0);
	r = 0;
	i = 0;
	while (s[i++])
	{
		if (s[i - 1] != c && (!(i - 1) || s[i - 2] == c))
			r++;
	}
	if (!(a = (char **)malloc(sizeof(char *) * r + 1)))
		return (NULL);
	return (get_strs(s, a, c) ? a : NULL);
}
