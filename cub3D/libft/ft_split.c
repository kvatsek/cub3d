/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:13:15 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/19 14:56:19 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**memfree(char **sp, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(sp[i]);
		i++;
	}
	free(sp);
	return (NULL);
}

static char	**zapol(char **split, char const *s, char c, int col)
{
	size_t	i;
	int		start;
	int		d;
	int		n;

	n = 0;
	i = 0;
	while (n < col && s[i] != '\0')
	{
		d = 0;
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
		{
			i++;
			d++;
		}
		split[n] = ft_substr(s, start, d);
		if (!split[n])
			return (memfree(split, n));
		n++;
	}
	return (split);
}

char		**ft_split(char const *s, char c)
{
	int		col;
	size_t	i;
	char	**split;

	if (!s)
		return (NULL);
	i = 0;
	col = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		col++;
	}
	if (ft_strlen(s) > 0 && s[ft_strlen(s) - 1] == c)
		col = col - 1;
	if ((split = (char**)malloc((col + 1) * sizeof(char*))) == NULL)
		return (NULL);
	split = zapol(split, s, c, col);
	if (split)
		split[col] = NULL;
	return (split);
}
