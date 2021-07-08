/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:50:34 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 12:50:41 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	size_t	k;
	char	*str;

	k = 0;
	str = (char *)dst;
	while (k < n)
	{
		str[k] = c;
		k++;
	}
	return (dst);
}
