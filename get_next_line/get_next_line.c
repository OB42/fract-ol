/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:16:35 by obenazzo          #+#    #+#             */
/*   Updated: 2017/12/02 14:29:09 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		new_fd(int const fd, t_list *t, t_list **fds)
{
	if (!t || !(t->content = malloc(sizeof(t_fd))) ||
	(((t_fd *)(t->content))->r = read(fd, ((t_fd *)(t->content))->b, BS)) == -1)
	{
		(t && t->content) ? free(t->content) : 0;
		t ? free(t) : 0;
		return (0);
	}
	((t_fd *)(t->content))->b[((t_fd *)(t->content))->r] = 0;
	((t_fd *)(t->content))->fd = fd;
	ft_lstadd(fds, t);
	return (1);
}

t_fd	*get_fd(int const fd)
{
	static struct s_list	*fds;
	struct s_list			*t;

	if (fd < 0 || BUFF_SIZE < 1)
		return (0);
	t = fds;
	while (t)
	{
		if (((t_fd *)(t->content))->fd == fd)
			return (t->content);
		t = t->next;
	}
	return (new_fd(fd, ft_lstnew(0, 0), &fds) ? get_fd(fd) : 0);
}

char	*reall(char *str, int size)
{
	char *temp;

	if (!(temp = malloc(size + 1)))
		return (0);
	if (str)
	{
		ft_strncpy(temp, str, size);
		free(str);
	}
	else
		temp[0] = 0;
	temp[size] = 0;
	return (temp);
}

int		get_next_line_part(char **line, t_fd *t)
{
	size_t	i;
	size_t	l;
	int		r;

	r = 0;
	if (!t->b[0] && (!t->r || (r = read(t->fd, t->b, BUFF_SIZE)) < 1))
		return (r == -1 ? -1 : (t->r && *line && *line[0]));
	if (r)
		t->b[r] = 0;
	i = (size_t)ft_strchr(t->b, 10);
	l = ft_strlen(t->b);
	i = i ? (i - (size_t)t->b) : l;
	if (!(*line = reall(*line, (*line ? ft_strlen(*line) : 0) + i)))
		return (-1);
	ft_strncpy(*line + ft_strlen(*line), t->b, i);
	if (i < l && ft_strncpy(t->b, t->b + i + 1, BUFF_SIZE - i))
		return (1);
	if ((r = read(t->fd, t->b, BUFF_SIZE)) == -1)
		return (-1);
	t->b[r] = 0;
	return (get_next_line_part(line, t));
}

int		get_next_line(int const fd, char **line)
{
	t_fd *t;

	if (!(t = get_fd(fd)))
		return (-1);
	*line = 0;
	return (get_next_line_part(line, t));
}
