/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:44:03 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 09:52:36 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*sd(char *d, char *s, size_t n)
{
	size_t	t;

	t = n;
	while (t > 0)
	{
		d[t - 1] = s[t - 1];
		t--;
	}
	return (d);
}

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	t;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	if (s < d)
	{
		d = sd(d, s, n);
	}
	else
	{
		t = 0;
		while (t < n)
		{
			d[t] = s[t];
			t++;
		}
	}
	return (d);
}
