/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:48:29 by aantonin          #+#    #+#             */
/*   Updated: 2021/03/05 12:11:31 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

void	replace(t_sprite *m1, t_sprite *m2)
{
	int		x;
	int		y;
	float	d;

	x = m1->x;
	y = m1->y;
	d = m1->dist;
	m1->x = m2->x;
	m1->y = m2->y;
	m1->dist = m2->dist;
	m2->x = x;
	m2->y = y;
	m2->dist = d;
}

void	sprite_mas_sort(t_params *pr)
{
	int		i;
	int		j;

	i = 1;
	while (i < pr->spr_coun)
	{
		j = 0;
		while (j < pr->spr_coun - i)
		{
			if (pr->spr_mas[j].dist < pr->spr_mas[j + 1].dist)
			{
				replace(&(pr->spr_mas[j]), &(pr->spr_mas[j + 1]));
			}
			j++;
		}
		i++;
	}
}

void	flags_nol(t_params *pr)
{
	int		i;

	i = 0;
	while (i < pr->spr_coun)
	{
		pr->spr_mas[i].fl = 0;
		i++;
	}
}

void	sprite_draw(t_player *pl, float g, int xx, int i)
{
	float	k;
	int		j;
	int		color;
	float	q[3];

	k = (pl->p.res_w / (2 * tan(M_PI / 3))) / pl->p.spr_mas[i].dist;
	q[0] = (pl->p.spr_mas[i].dist * tan(g) + 1 / 2) *
	pl->p.tex[4].width + pl->p.tex[4].width / 4;
	j = pl->p.res_h / 2 - (int)k;
	q[1] = 0;
	q[2] = pl->p.tex[4].height / (k * 2);
	if (q[0] > 0 && q[0] < pl->p.tex[4].width && j > 0)
	{
		while (j < (pl->p.res_h / 2) + (int)k * 2 && q[1] < pl->p.tex[4].width)
		{
			color = my_put_texture(&pl->p.tex[4], (int)q[0], (int)q[1]);
			if (color != 0x00000000)
				my_mlx_pixel_put(&pl->img_str, xx, j, color);
			j++;
			q[1] += q[2];
		}
	}
}

void	draw_sprites(t_player *pl, float a, int xx)
{
	int		i;
	float	dx;
	float	dy;
	float	b;
	float	g;

	i = 0;
	while (i < pl->p.spr_coun)
	{
		if (pl->p.spr_mas[i].fl == 1)
		{
			dx = pl->x - (pl->p.spr_mas[i].x + 0.5);
			dy = pl->y - (pl->p.spr_mas[i].y + 0.5);
			b = atan2(dy, dx);
			if (a > b)
				g = a - b;
			else
				g = b - a;
			sprite_draw(pl, g, xx, i);
		}
		i++;
	}
}
