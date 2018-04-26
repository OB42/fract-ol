/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pr_atoi(const char *str)
{
	int			i;
	long long	nb;
	int			sign;

	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = *str == '-' ? -1 : 1;
	if (ft_strchr("+-", *str))
		str++;
	nb = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb * sign < -2147483648 || nb * sign > 2147483647)
			print_error(ERR_NBR_PARSING);
		i++;
	}
	if (!i || str[i])
		print_error(ERR_NBR_PARSING);
	return (nb * sign);
}
