/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:11:41 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/15 13:26:38 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		v;

	i = 0;
	j = ft_strlen(to_find);
	if (*to_find == '\0')
		return ((char *)str);
	if (j > ft_strlen(str) || len == 0 || j > len)
		return (NULL);
	while (str[i + j - 1] != '\0' && i < len - j + 1)
	{
		if (*(str + i) == *to_find)
		{
			v = 1;
			while (*(str + i + v) == *(to_find + v) && v < j)
				v++;
			if (to_find[v] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
