/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_rep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:46:04 by aantonin          #+#    #+#             */
/*   Updated: 2021/03/06 10:17:41 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

void	check_repeat(char **map, int i)
{
	int		k;
	int		j;

	k = 0;
	while (k < i)
	{
		j = k + 1;
		while (j < i)
		{
			if (ft_strncmp(map[k], map[j], 2) == 0 && map[k][0] != '\0')
				error_exit(1);
			j++;
		}
		k++;
	}
}

void	cheak_res(void *mlx, int *h, int *w)
{
	int	max_w;
	int	max_h;

	mlx_get_screen_size(mlx, &max_w, &max_h);
	if (*w > max_w)
		*w = max_w;
	if (*h > max_h)
		*h = max_h;
	if (*w < 16)
		*w = 32;
	if (*h < 16)
		*h = 32;
}

int		cl_cub(void)
{
	exit(1);
	return (1);
}
