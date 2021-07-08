/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:39:17 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 09:41:48 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ss(char c, const char *set)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(set) && *(set + i) != c)
		i++;
	if (i == ft_strlen(set))
		return (0);
	return (1);
}

static int		nn(char const *s1, char const *set)
{
	size_t		i;
	char		c;

	i = 0;
	c = *s1;
	while (i < ft_strlen(s1) && ss(c, set) == 1)
	{
		i++;
		c = *(s1 + i);
	}
	return (i);
}

static int		kk(char const *s1, char const *set, size_t n)
{
	size_t		i;
	char		c;

	i = ft_strlen(s1);
	c = *(s1 + i - 1);
	while (i > n && ss(c, set) == 1)
	{
		i--;
		c = *(s1 + i);
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		k;
	size_t		i;
	size_t		n;
	char		*trim;

	if (!s1 || !set)
		return (0);
	n = nn(s1, set);
	k = kk(s1, set, n);
	if (n > k)
	{
		trim = malloc(sizeof(char));
		trim[0] = '\0';
		return (trim);
	}
	if ((trim = malloc((k - n + 2) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (i + n <= k)
	{
		*(trim + i) = *(s1 + i + n);
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
