/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:09:48 by aantonin          #+#    #+#             */
/*   Updated: 2021/03/06 09:52:06 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

int			count_sprite(char **map, int n)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < n)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '2')
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

t_sprite	*write_down_sprite(char **map, int n, int count)
{
	int			i;
	int			j;
	int			k;
	t_sprite	*spr;

	if (!(spr = malloc((count + 1) * sizeof(t_sprite))))
		error_exit(3);
	i = 0;
	k = 0;
	while (i < n && k < count)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '2')
			{
				spr[k].y = i;
				spr[k].x = j;
				k++;
			}
			j++;
		}
		i++;
	}
	return (spr);
}

void		error_exit(int e)
{
	if (e == 0)
		write(1, "Error\n There is no map or too many arguments\n", 45);
	else if (e == 1)
		write(1, "Error\n invalid map\n", 19);
	else if (e == 2)
		write(1, "Error\n too many players\n", 24);
	else if (e == 3)
		write(1, "Error\n error of malloc\n", 23);
	else if (e == 4)
		write(1, "Error\n invalid map file name\n", 29);
	else if (e == 5)
		write(1, "Error\n no player\n", 17);
	else if (e == 6)
		write(1, "Error\n invalid file of texture\n", 31);
	exit(1);
}

t_params	read_before(char **map, int i)
{
	t_params params;

	params = params_nol();
	read_res(map[0], &params);
	read_texture(map, &params, i);
	return (params);
}
