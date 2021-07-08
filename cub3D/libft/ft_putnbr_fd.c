/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:57:10 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 09:33:10 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_nb1(char num_c, int fd)
{
	write(fd, &num_c, 1);
}

static int		proverka(int n, int fd)
{

	if (n < 0)
	{
		if (n == -2147483648)
		{
			print_nb1('-', fd);
			print_nb1('2', fd);
			n = n % 1000000000;
			return (n * (-1));
		}
		else
		{
			print_nb1('-', fd);
			return (n * (-1));
		}
	}
	if (n == 0)
		print_nb1('0', fd);
	return (n);
}

void			ft_putnbr_fd(int nb, int fd)
{
	long int	control;
	int			nb1;
	int			logik;

	control = 1000000000;
	logik = 0;
	nb = proverka(nb, fd);
	if (nb > 0)
	{
		while (control > 0)
		{
			nb1 = nb / control;
			nb = nb % control;
			control = control / 10;
			if (nb1 > 0 || logik == 1)
			{
				print_nb1(nb1 + 48, fd);
				logik = 1;
			}
		}
	}
}
