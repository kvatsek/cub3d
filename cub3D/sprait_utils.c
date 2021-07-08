/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprait_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:54:18 by aantonin          #+#    #+#             */
/*   Updated: 2021/02/27 12:55:38 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

void	sprite_dist(t_player *pl)
{
	int		t;
	float	fx;
	float	fy;

	t = 0;
	while (t < pl->p.spr_coun)
	{
		fx = pl->p.spr_mas[t].x + 0.5;
		fy = pl->p.spr_mas[t].y + 0.5;
		pl->p.spr_mas[t].dist = sqrt((fx - pl->x) *
		(fx - pl->x) + (fy - pl->y) * (fy - pl->y));
		t++;
	}
	t = 0;
}

void	init_sprites(t_player *pl)
{
	sprite_dist(pl);
	sprite_mas_sort(&(pl->p));
	flags_nol(&(pl->p));
}
