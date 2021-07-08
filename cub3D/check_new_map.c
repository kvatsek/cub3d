/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_new_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:28:48 by aantonin          #+#    #+#             */
/*   Updated: 2021/03/05 20:04:11 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

int		check_f0(char **map, int i, int j, int n)
{
	int r;

	r = 0;
	while (r + i <= n)
	{
		if (map[i + r][j] == ' ')
			error_exit(1);
		if (map[i + r][j] == '1')
			return (1);
		r++;
	}
	return (0);
}

int		check_f1(char **map, int i, int j)
{
	int r;

	r = 0;
	while (i - r >= 0)
	{
		if (map[i - r][j] == ' ')
			error_exit(1);
		if (map[i - r][j] == '1')
			return (1);
		r++;
	}
	return (0);
}

int		check_f2(char **map, int i, int j)
{
	int r;

	r = 0;
	while (j - r >= 0)
	{
		if (map[i][j - r] == ' ')
			error_exit(1);
		if (map[i][j - r] == '1')
			return (1);
		r++;
	}
	return (0);
}

int		check_f3(char **map, int i, int j)
{
	int r;

	r = 0;
	while (map[i][j + r] != '\0')
	{
		if (map[i][j + r] == ' ')
			error_exit(1);
		if (map[i][j + r] == '1')
			return (1);
		r++;
	}
	return (0);
}

void	check_2_new(char **map, int i, int j, int n)
{
	int		flags[4];
	int		k;

	k = 3;
	while (k >= 0 && k--)
		flags[k] = 0;

	flags[0] = check_f0(map, i, j, n);
	flags[1] = check_f1(map, i, j);
	flags[2] = check_f2(map, i, j);
	flags[3] = check_f3(map, i, j);
	if (flags[0] == 0 || flags[1] == 0 || flags[2] == 0 || flags[3] == 0)
		error_exit(1);
}

void	check_new_map(char **map, int n)
{
	int		i;
	int		j;
	

	
	i = 0;
	while (i < n)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0')
			{
				check_2_new(map, i, j, n);
			}
			j++;
		}
		i++;
	}
}
