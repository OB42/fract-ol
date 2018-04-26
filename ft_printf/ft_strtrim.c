/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 03:18:27 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/05 03:18:30 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*t;
	int		r;
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (l < ft_strlen((char *)s) && ft_isspace(s[l]))
		l++;
	if (l == ft_strlen((char *)s))
	{
		if (!(t = (char *)(malloc(1))))
			return (0);
		*t = 0;
		return (t);
	}
	r = ft_strlen((char *)s) - 1;
	while (r > -1 && ft_isspace(s[r]))
		r--;
	if (!(t = (char *)(malloc(r - l + 2))))
		return (0);
	ft_strncpy(t, (char *)(s + l), r - l + 1);
	t[r - l + 1] = '\0';
	return (t);
}
