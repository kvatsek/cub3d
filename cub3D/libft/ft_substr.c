/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:42:30 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/06 15:26:54 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str_n;
	size_t		k;
	size_t		sl;

	if (!s)
		return (0);
	sl = ft_strlen(s);
	if (start >= sl)
		return (ft_strdup(""));
	str_n = malloc((len + 1) * sizeof(char));
	if (!str_n)
		return (NULL);
	k = 0;
	while (k + start < sl && k < len)
	{
		*(str_n + k) = *(s + start + k);
		k++;
	}
	str_n[k] = '\0';
	return (str_n);
}
