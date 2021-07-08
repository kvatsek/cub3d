/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:49:26 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 12:49:32 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t k)
{
	size_t				n;
	const unsigned char	*s1;
	const unsigned char	*s2;

	n = 0;
	s1 = (const unsigned char*)arr1;
	s2 = (const unsigned char*)arr2;
	while (n < k && s1[n] == s2[n])
		n++;
	if (n != k)
		return (s1[n] - s2[n]);
	return (0);
}
