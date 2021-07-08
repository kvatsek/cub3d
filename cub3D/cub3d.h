/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:59:31 by aantonin          #+#    #+#             */
/*   Updated: 2021/02/27 20:07:54 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include <math.h>

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_tex {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	char		*fn;
	int			width;
	int			height;
	int			endian;
	float		kh;
	float		kw;
}				t_tex;

typedef struct	s_color {
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_pixel {
	float		distance;
	int			sw;
	float		k;
}				t_pixel;

typedef struct	s_sprite {
	int			x;
	int			y;
	float		dist;
	int			fl;
}				t_sprite;

typedef struct	s_params {
	int			res_w;
	int			res_h;
	int			cf;
	int			cl;
	t_tex		tex[5];
	int			spr_coun;
	t_sprite	*spr_mas;

}				t_params;

typedef struct	s_player {
	float		x;
	float		y;
	float		angle;
	t_data		img_str;
	void		*init_w;
	void		*window;
	char		**map;
	int			n;
	t_params	p;
	int			stop;
}				t_player;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_rectangle(int x, int y, int l, t_data *img, int color);
void			draw_map(char **map, int n, t_params params, int flag);
t_player		draw_player(char **map, int n, t_player player);
int				cl_cub(void);
void			error_exit(int e);
t_params		params_nol();
void			read_texture(char **map, t_params *p, int n);
void			read_res(char *r, t_params *p);
void			check_new_map(char **map, int n);
void			get_texture(t_params *p, void *mlx);
void			init_sprites(t_player *player);
void			flags_nol(t_params *pr);
void			draw_sprites(t_player *pl, float a, int xx);
int				my_put_texture(t_tex *tex, int x, int y);
void			bmp_save(t_player player);
int				count_sprite(char **map, int n);
t_sprite		*write_down_sprite(char **map, int n, int count);
t_params		read_before(char **map, int i);
int				read_color(char *m);
int				key_press(int key, t_player *player);
void			draw_a_lot_of_rays(t_player *player);
float			nsew_help(float a);
void			nsew_det(int xy[2], float fxy[2], t_pixel *n);
void			found_sp(int x, int y, t_params *p);
t_pixel			draw_ray(float pxy[2], char **map, float angle, t_params *p);
void			sprite_dist(t_player *pl);
void			sprite_mas_sort(t_params *pr);
void			check_repeat(char **map, int i);
void			cheak_res(void *mlx, int *h, int *w);

#endif
