/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:59:29 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 10:15:03 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_nb1(char *itog, char num_c, int fd)
{
	*(itog + fd) = num_c;
}

static int		proverka(char *itog, int n)
{
	if (n < 0)
	{
		print_nb1(itog, '-', 0);
		return (-1);
	}
	return (0);
}

static char		*preobr(char *itog, int n, int i)
{
	long int	control;
	int			nb1;
	int			logik;

	control = 1000000000;
	logik = 0;
	while (control > 0)
	{
		nb1 = n / control;
		n = n % control;
		control = control / 10;
		if (nb1 > 0 || logik == 1)
		{
			print_nb1(itog, nb1 + 48, i);
			logik = 1;
			i++;
		}
	}
	itog[i] = '\0';
	return (itog);
}

char			*ft_itoa(int n)
{
	char		*itog;
	int			i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if ((itog = malloc(13 * sizeof(char))) == NULL)
		return (NULL);
	if (proverka(itog, n) == -1)
	{
		i = 1;
		n = n * (-1);
	}
	itog = preobr(itog, n, i);
	return (itog);
}
