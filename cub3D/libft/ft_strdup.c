/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:24:48 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/19 14:30:37 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		n;
	char		*str2;
	size_t		i;

	n = ft_strlen(src);
	str2 = malloc((n + 1) * sizeof(char));
	if (!str2)
		return (str2);
	i = 0;
	while (i < n)
	{
		str2[i] = src[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
