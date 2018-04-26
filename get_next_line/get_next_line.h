/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:16:35 by obenazzo          #+#    #+#             */
/*   Updated: 2017/12/02 14:29:09 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# define BUFF_SIZE 100000
# define BS BUFF_SIZE

typedef struct	s_fd
{
	char	b[BUFF_SIZE + 1];
	int		fd;
	int		r;
}				t_fd;
t_fd			*get_fd(int const fd);
int				get_next_line(int const fd, char **line);
#endif
