/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:48:58 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/19 13:43:09 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*a;
	size_t			k;

	a = (unsigned char *)arr;
	k = 0;
	while (k < n)
	{
		if (a[k] == (unsigned char)c)
			return ((char *)(a + k));
		k++;
	}
	return (NULL);
}
