/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:31:09 by aantonin          #+#    #+#             */
/*   Updated: 2021/02/27 11:32:36 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pixel		draw_ray(float pxy[2], char **map, float angle, t_params *p)
{
	float	fxy[2];
	t_pixel	n;
	int		xy[2];

	n.distance = 0;
	fxy[0] = pxy[0] + cos(angle) / 100;
	fxy[1] = pxy[1] + sin(angle) / 100;
	while (map[(int)floor(fxy[1])][(int)floor(fxy[0])] == '0' ||\
	map[(int)floor(fxy[1])][(int)floor(fxy[0])] == '2')
	{
		if (map[(int)floor(fxy[1])][(int)floor(fxy[0])] == '2')
			found_sp((int)floor(fxy[0]), (int)floor(fxy[1]), p);
		xy[0] = fxy[0];
		xy[1] = fxy[1];
		fxy[0] = fxy[0] + cos(angle) / 100;
		fxy[1] = fxy[1] + sin(angle) / 100;
	}
	n.distance = sqrt((fxy[0] - pxy[0]) * (fxy[0] - pxy[0])
			+ (fxy[1] - pxy[1]) * (fxy[1] - pxy[1]));
	nsew_det(xy, fxy, &n);
	return (n);
}

int			draw_wall(int g[2], t_player *player, float k, t_pixel *n)
{
	float	s;
	float	d;
	int		xxx;
	int		color;
	int		j;

	d = 0;
	j = (int)(player->p.res_h / 2 + k);
	s = player->p.tex[n->sw].height / (k * 2);
	if (n->k < 0)
		n->k = 0;
	(n->k >= 1) ? n->k = 0.99 : 0;
	xxx = (int)((player->p.tex[n->sw].width - 1) * n->k);
	while (g[0] < j)
	{
		if (d >= 0 && d < player->p.tex[n->sw].height && \
		g[0] < player->p.res_h && g[0] > 0)
		{
			color = my_put_texture(&player->p.tex[n->sw], xxx, (int)d);
			my_mlx_pixel_put(&player->img_str, g[1], g[0], color);
		}
		g[0]++;
		d = d + s;
	}
	return (g[0]);
}

void		draw3d(t_pixel *n, int xx, t_player *player, float a)
{
	float	k;
	int		i;
	int		j;
	int		g[2];

	k = (player->p.res_w / (2 * tan(M_PI / 3))) /
		(n->distance * cos(a - player->angle));
	j = 0;
	i = (int)(player->p.res_h / 2 - k);
	while (j < i)
	{
		if (j < player->p.res_h - 1 && j > 0)
			my_mlx_pixel_put(&player->img_str, xx, j, player->p.cl);
		j++;
	}
	g[0] = i;
	g[1] = xx;
	i = draw_wall(g, player, k, n);
	while (i < player->p.res_h - 1)
	{
		if (i < player->p.res_h - 1 && i > 0)
			my_mlx_pixel_put(&player->img_str, xx, i, player->p.cf);
		i++;
	}
}

void		draw_a_lot_of_rays(t_player *player)
{
	float	da;
	float	a;
	t_pixel	n;
	int		xx;
	float	pxy[2];

	da = M_PI / 3 / player->p.res_w;
	a = player->angle - M_PI / 6;
	xx = 1;
	while (a < player->angle + M_PI / 6 && xx < player->p.res_w)
	{
		flags_nol(&(player->p));
		pxy[0] = player->x;
		pxy[1] = player->y;
		n = draw_ray(pxy, player->map, a, &(player->p));
		draw3d(&n, xx, player, a);
		draw_sprites(player, a, xx);
		flags_nol(&(player->p));
		xx++;
		a += da;
	}
}
