/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 03:18:27 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/05 03:18:30 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *l;
	t_list *temp;
	t_list *save;

	if (!lst || !f)
		return (0);
	temp = (*f)(lst);
	l = ft_lstnew(temp->content, temp->content_size);
	save = l;
	lst = lst->next;
	while (lst)
	{
		temp = (*f)(lst);
		l->next = ft_lstnew(temp->content, temp->content_size);
		l = l->next;
		lst = lst->next;
	}
	return (save);
}
