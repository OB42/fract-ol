/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 04:30:43 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/06 10:52:11 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int s;

	s = 0;
	while (s1[s] == s2[s] && s2[s] != '\0')
		s++;
	return (((unsigned char)s1[s] - (unsigned char)s2[s]));
}
