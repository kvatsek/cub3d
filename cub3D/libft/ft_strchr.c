/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:51:26 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 12:51:32 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*a;
	size_t	k;

	a = (char *)str;
	k = 0;
	while (a[k] != '\0')
	{
		if (a[k] == ch)
			return (&a[k]);
		k++;
	}
	if (a[k] == ch)
		return (&a[k]);
	return (NULL);
}
