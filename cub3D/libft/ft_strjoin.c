/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:46:00 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/06 15:29:53 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	size_t	k;
	char	*str_join;

	if (!s1 || !s2)
		return (NULL);
	k = ft_strlen(s1);
	n = ft_strlen(s2);
	str_join = malloc((k + n + 1) * sizeof(char));
	if (!str_join)
		return (NULL);
	i = 0;
	while (i < k)
	{
		*(str_join + i) = *(s1 + i);
		i++;
	}
	while (i < k + n)
	{
		*(str_join + i) = *(s2 + i - k);
		i++;
	}
	str_join[i] = '\0';
	return (str_join);
}
