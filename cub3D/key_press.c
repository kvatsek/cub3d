/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:14:51 by aantonin          #+#    #+#             */
/*   Updated: 2021/02/27 16:19:53 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_13(t_player *player)
{
	player->y += (sin(player->angle)) / 10;
	player->x += (cos(player->angle)) / 10;
	if (player->map[(int)floor(player->y)][(int)floor(player->x)] == '1' || \
	player->map[(int)floor(player->y)][(int)floor(player->x)] == '2')
	{
		player->y -= (sin(player->angle)) / 10;
		player->x -= (cos(player->angle)) / 10;
	}
}

void	key_1(t_player *player)
{
	player->y += (sin(player->angle - M_PI)) / 10;
	player->x += (cos(player->angle - M_PI)) / 10;
	if (player->map[(int)(player->y)][(int)(player->x)] == '1' ||\
	player->map[(int)(player->y)][(int)(player->x)] == '2')
	{
		player->y -= (sin(player->angle - M_PI)) / 10;
		player->x -= (cos(player->angle - M_PI)) / 10;
	}
}

void	key_0(t_player *player)
{
	player->y += sin(player->angle - M_PI / 2) / 10;
	player->x += cos(player->angle - M_PI / 2) / 10;
	if (player->map[(int)(player->y)][(int)(player->x)] == '1' ||\
	player->map[(int)(player->y)][(int)(player->x)] == '2')
	{
		player->y -= (sin(player->angle - M_PI / 2)) / 10;
		player->x -= (cos(player->angle - M_PI / 2)) / 10;
	}
}

void	key_2(t_player *player)
{
	player->y += (sin(player->angle + M_PI / 2)) / 10;
	player->x += (cos(player->angle + M_PI / 2)) / 10;
	if (player->map[(int)(player->y)][(int)(player->x)] == '1' ||\
	player->map[(int)(player->y)][(int)(player->x)] == '2')
	{
		player->y -= (sin(player->angle + M_PI / 2)) / 10;
		player->x -= (cos(player->angle + M_PI / 2)) / 10;
	}
}

int		key_press(int key, t_player *player)
{
	mlx_clear_window(player->init_w, player->window);
	if (key == 13)
		key_13(player);
	if (key == 1)
		key_1(player);
	if (key == 0)
		key_0(player);
	if (key == 2)
		key_2(player);
	if (key == 124)
		player->angle += M_PI / 16;
	if (key == 123)
		player->angle -= M_PI / 16;
	if (key == 53)
		exit(0);
	if (player->p.spr_coun > 0)
		init_sprites(player);
	draw_a_lot_of_rays(player);
	mlx_put_image_to_window(player->init_w, player->window,
	player->img_str.img, 0, 0);
	return (1);
}
