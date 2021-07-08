/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:22:11 by aantonin          #+#    #+#             */
/*   Updated: 2020/12/17 14:37:38 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*free_n(char *src)
{
	free(src);
	return (0);
}

char	*ft_strjoin_f(char *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	size_t	k;
	char	*str_join;

	k = ft_strlen(s1);
	n = ft_strlen(s2);
	if (!(str_join = malloc((k + n + 1) * sizeof(char))))
		return (free_n(s1));
	i = 0;
	while (i < k)
	{
		str_join[i] = s1[i];
		i++;
	}
	while (i < k + n)
	{
		str_join[i] = s2[i - k];
		i++;
	}
	str_join[i] = '\0';
	free(s1);
	return (str_join);
}