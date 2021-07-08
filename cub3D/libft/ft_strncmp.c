/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:52:48 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 11:43:35 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		k;
	size_t		l;
	int			lv1;
	int			lv2;

	k = 0;
	if (n == 0)
		return (0);
	lv1 = *(s1 + k) == *(s2 + k) && (k < n - 1);
	lv2 = *(s1 + k) != '\0' && *(s2 + k) != '\0';
	while (lv1 && lv2)
	{
		k++;
		lv1 = *(s1 + k) == *(s2 + k) && (k < n - 1);
		lv2 = *(s1 + k) != '\0' && *(s2 + k) != '\0';
	}
	l = (unsigned char)*(s1 + k) - (unsigned char)*(s2 + k);
	return (l);
}
