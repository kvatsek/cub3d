/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:49:56 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 12:50:03 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*c;
	size_t	t;

	d = (char *)dst;
	c = (char *)src;
	if (!dst && !src)
		return (dst);
	t = 0;
	while (t < n)
	{
		d[t] = c[t];
		t++;
	}
	return (d);
}
