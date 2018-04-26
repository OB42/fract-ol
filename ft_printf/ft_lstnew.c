/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 03:18:27 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/05 03:18:30 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	struct s_list *s;

	s = (struct s_list *)malloc(sizeof(struct s_list));
	if (!s)
		error();
	s->next = 0;
	if (!content)
		s->content = 0;
	else
	{
		s->content = (void *)malloc(content_size);
		if (!s->content)
			error();
		ft_memcpy(s->content, content, content_size);
	}
	s->content_size = content ? content_size : 0;
	return (s);
}
