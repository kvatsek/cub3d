/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:32:58 by aantonin          #+#    #+#             */
/*   Updated: 2021/03/05 17:20:59 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		my_put_texture(t_tex *tex, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

float	nsew_help(float a)
{
	while (a > 1)
	{
		a = a - 1;
	}
	return (a);
}

void	nsew_help2(t_pixel *n, float a, int b)
{
	n->sw = b;
	n->k = nsew_help(a);
}

void	nsew_det(int xy[2], float fxy[2], t_pixel *n)
{
	static int l;

	if (!l)
		l = 0;
	if ((xy[1]) != (int)floor(fxy[1]) && xy[0] != (int)floor(fxy[0]))
	{
		n->sw = l;
		n->k = 0;
	}
	if (xy[1] == (int)floor(fxy[1]) && xy[0] == (int)floor(fxy[0]))
	{
		if (xy[0] - fxy[0] > xy[1] - fxy[1])
			xy[0] = (int)floor(fxy[0]);
		else
			xy[1] = (int)floor(fxy[1]);
	}
	if (xy[1] > floor(fxy[1]) && xy[0] == floor(fxy[0]))
		nsew_help2(n, fxy[0], 0);
	else if (xy[0] < (int)floor(fxy[0]) && xy[1] == (int)floor(fxy[1]))
		nsew_help2(n, fxy[1], 3);
	else if (xy[1] < (int)floor(fxy[1]) && xy[0] == (int)floor(fxy[0]))
		nsew_help2(n, fxy[0], 1);
	else if (xy[0] > (int)floor(fxy[0]) && xy[1] == (int)floor(fxy[1]))
		nsew_help2(n, fxy[1], 2);
	l = n->sw;
}
