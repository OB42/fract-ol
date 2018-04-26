/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 01:53:58 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/08 09:44:25 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**w_blank(char *str, char **words, int save, int w)
{
	int s;

	s = 0;
	while (str[s] && (str[s] == ' ' || str[s] == '\n' || str[s] == '\t'))
		s++;
	if (save)
		return (w_char(str + s, words, save, w));
	if (str[s])
		return (w_char(str + s, words, save, w));
	words[w] = 0;
	return (words);
}

char	**w_char(char *str, char **words, int save, int w)
{
	int		s;

	s = 0;
	while (str[s] && str[s] != ' ' && str[s] != '\n' && str[s] != '\t')
		s++;
	if (save)
	{
		return (str[s] ? w_blank(str + s, words, save + 1, w) :
		w_blank(str + s - w, pr_malloc(sizeof(char *) * (save + 1) + 1), 0, 0));
	}
	if (s)
		words[w++] = (char*)pr_malloc(sizeof(char) * s + 1);
	s = 0;
	while (str[s] && str[s] != ' ' && str[s] != '\n' && str[s] != '\t')
	{
		words[w - 1][s] = str[s];
		s++;
	}
	if (s)
		words[w - 1][s] = '\0';
	if (str[s])
		return (w_blank(str + s, words, save, w));
	words[w] = 0;
	return (words);
}

char	**split(char *str)
{
	char		**words;

	words = 0;
	return (w_blank(str, words, 1, ft_strlen(str)));
}
