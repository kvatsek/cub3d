/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:57:21 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/06 20:12:54 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int ch, size_t n)
{
	unsigned char	*d;
	unsigned char	*c;
	size_t			t;
	unsigned char	b;

	d = (unsigned char *)dst;
	c = (unsigned char *)src;
	b = (unsigned char)ch;
	if (!dst && !src)
		return (d);
	t = 0;
	while (t < n && c[t] != b)
	{
		d[t] = c[t];
		t++;
	}
	if (c[t] == b)
	{
		d[t] = c[t];
		return (&d[t + 1]);
	}
	return (NULL);
}
