/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:39:09 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 11:10:10 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	make_nbr(int k, const char *str, int i)
{
	int		d;
	int		nbr;
	int		d10;

	d10 = 1;
	nbr = 0;
	while (k >= i)
	{
		d = str[k] - 48;
		nbr = nbr + d * d10;
		d10 = d10 * 10;
		if (str[k] < 48 || str[k] > 57)
		{
			nbr = 0;
			d10 = 1;
		}
		k--;
	}
	return (nbr);
}

static int	probel(char c)
{
	int		a;

	a = 0;
	if (c == '\f' || c == ' ' || c == '\r')
		a = 1;
	if (c == '\t' || c == '\n' || c == '\v')
		a = 1;
	return (a);
}

int			ft_atoi(const char *str)
{
	int		k;
	int		nbr;
	int		i[2];

    k = 0;
	while (probel(str[k]) == 1)
		k++;
	if ((str[k] < 48 || str[k] > 57) && str[k] != '-' && str[k] != '+')
		return (0);
	i[1] = 0;
	if (str[k] == '-' || str[k] == '+')
	{
		if (str[k] == '-')
			i[1] = 1;
		k++;
		if (ft_strncmp(str, "-2147483648", 11) == 0)
			return (-2147483648);
	}
	i[0] = ft_strlen(str) - 1;
	while (str[i[0]] < 48 || str[i[0]] > 57)
		i[0]--;
	nbr = make_nbr(i[0], str, k);
	if (i[1] == 1)
		return (-1 * nbr);
	return (nbr);
}
