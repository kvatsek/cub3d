/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:54:35 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 12:54:41 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*a;
	size_t	k;
	size_t	n;

	a = (char *)str;
	n = ft_strlen(a);
	k = n;
	while (k > 0)
	{
		if (a[k] == ch)
			return (&a[k]);
		k--;
	}
	if (*a == ch)
		return (&a[0]);
	return (NULL);
}
