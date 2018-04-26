/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_lines(char *file)
{
	int		fd;
	char	c;
	int		r;
	int		lines;

	lines = 0;
	if ((fd = open(file, O_RDONLY, S_IRUSR)) == -1)
		print_error(ERR_FILE_READING);
	while ((r = read(fd, &c, 1)) == 1)
		lines += c == '\n';
	lines += c != '\n';
	if (r == -1)
		print_error(ERR_FILE_READING);
	close(fd);
	return (lines);
}

int		ft_strarrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

t_v		*parse_line(char *line, int *max, int y)
{
	char		**temp;
	int			len;
	t_v			*x;
	int			i;

	if (!(temp = split(line)))
		print_error(ERR_PARSING);
	len = ft_strarrlen(temp);
	pr_free(line);
	if (*max != -1 && *max != len)
		print_error(ERR_PARSING);
	*max = len;
	x = pr_malloc((len + 1) * sizeof(t_v));
	ft_bzero(x, (len + 1) * sizeof(t_v));
	i = 0;
	while (i < len)
	{
		x[i].x = i;
		x[i].y = y;
		x[i].z = pr_atoi(temp[i]);
		pr_free(temp[i]);
		i++;
	}
	pr_free(temp);
	return (x);
}

t_p		get_map(char *file, int fd, t_v ***map)
{
	int		g;
	char	*line;
	int		m;
	int		i;
	int		max;

	max = -1;
	m = count_lines(file);
	*map = pr_malloc(sizeof(t_v *) * (m + 1));
	(*map)[m] = 0;
	i = 0;
	while ((g = get_next_line(fd, &line)) == 1)
	{
		if (i == m)
			print_error(ERR_PARSING);
		(*map)[i] = parse_line(line, &max, i);
		i++;
	}
	if (g == -1)
		print_error(ERR_GNL);
	return ((t_p){i, max});
}
