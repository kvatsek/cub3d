/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:37:43 by aantonin          #+#    #+#             */
/*   Updated: 2021/03/05 16:23:05 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float		angle_begin(char a)
{
	float angle;

	if (a == 'N')
		angle = 3 * M_PI / 2;
	if (a == 'S')
		angle = M_PI / 2;
	if (a == 'E')
		angle = 0;
	if (a == 'W')
		angle = M_PI;
	return (angle);
}

void				dp_help(char **map, t_player *player, int i, int j)
{
	player->y = i + 0.5;
	player->x = j + 0.5;
	player->angle = angle_begin(map[i][j]);
}

t_player			draw_player(char **map, int n, t_player player)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
			map[i][j] == 'E' || map[i][j] == 'W')
			{
				dp_help(map, &player, i, j);
				(player.p.spr_coun > 0) ? init_sprites(&player) : 0;
				map[i][j] = '0';
				draw_a_lot_of_rays(&player);
				return (player);
			}
			j++;
		}
		i++;
	}
	error_exit(5);
	return (player);
}

void				draw_map(char **map, int n, t_params params, int flag)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_player	player;

	mlx = mlx_init();
	cheak_res(mlx, &(params.res_h), &(params.res_w));
	mlx_win = mlx_new_window(mlx, params.res_w, params.res_h, "cub3d");
	img.img = mlx_new_image(mlx, params.res_w, params.res_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);
	player.n = n;
	player.map = map;
	player.init_w = mlx;
	player.window = mlx_win;
	player.img_str = img;
	get_texture(&params, mlx);
	player.p = params;
	player = draw_player(map, n, player);
	(flag == 1) ? bmp_save(player) : 0;
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, (1L << 0), &key_press, &player);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 17, 0L, &cl_cub, mlx_win);
	mlx_loop(mlx);
}

void				found_sp(int x, int y, t_params *p)
{
	int i;

	i = 0;
	while (i < p->spr_coun)
	{
		if (p->spr_mas[i].x == x && p->spr_mas[i].y == y)
			p->spr_mas[i].fl = 1;
		i++;
	}
}
