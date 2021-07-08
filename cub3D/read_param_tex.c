/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:13:01 by aantonin          #+#    #+#             */
/*   Updated: 2021/03/06 09:53:54 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

void	get_texture_help(t_params *p, void *mlx)
{
	if (!(p->tex[2].img = mlx_xpm_file_to_image(mlx, p->tex[2].fn,
	&p->tex[2].width, &p->tex[2].height)))
		error_exit(6);
	p->tex[2].addr = mlx_get_data_addr(p->tex[2].img,
	&p->tex[2].bits_per_pixel, &p->tex[2].line_length, &p->tex[2].endian);
	p->tex[2].kh = p->res_h / p->tex[2].height;
	p->tex[2].kw = p->res_w / p->tex[2].width;
	if (!(p->tex[3].img = mlx_xpm_file_to_image(mlx, p->tex[3].fn,
	&p->tex[3].width, &p->tex[3].height)))
		error_exit(6);
	p->tex[3].addr = mlx_get_data_addr(p->tex[3].img,
	&p->tex[3].bits_per_pixel, &p->tex[3].line_length, &p->tex[3].endian);
	p->tex[3].kh = p->res_h / p->tex[3].height;
	p->tex[3].kw = p->res_w / p->tex[3].width;
	if (!(p->tex[4].img = mlx_xpm_file_to_image(mlx, p->tex[4].fn,
	&p->tex[4].width, &p->tex[4].height)))
		error_exit(6);
	p->tex[4].addr = mlx_get_data_addr(p->tex[4].img,
	&p->tex[4].bits_per_pixel, &p->tex[4].line_length, &p->tex[4].endian);
	p->tex[4].kh = p->res_h / p->tex[4].height;
	p->tex[4].kw = p->res_w / p->tex[4].width;
}

void	get_texture(t_params *p, void *mlx)
{
	if (!(p->tex[0].img = mlx_xpm_file_to_image(mlx, p->tex[0].fn,
	&p->tex[0].width, &p->tex[0].height)))
		error_exit(6);
	p->tex[0].addr = mlx_get_data_addr(p->tex[0].img,
	&p->tex[0].bits_per_pixel, &p->tex[0].line_length, &p->tex[0].endian);
	p->tex[0].kh = p->res_h / p->tex[0].height;
	p->tex[0].kw = p->res_w / p->tex[0].width;
	if (!(p->tex[1].img = mlx_xpm_file_to_image(mlx, p->tex[1].fn,
	&p->tex[1].width, &p->tex[1].height)))
		error_exit(6);
	p->tex[1].addr = mlx_get_data_addr(p->tex[1].img,
	&p->tex[1].bits_per_pixel, &p->tex[1].line_length, &p->tex[1].endian);
	p->tex[1].kh = p->res_h / p->tex[1].height;
	p->tex[1].kw = p->res_w / p->tex[1].width;
	get_texture_help(p, mlx);
}

char	*read_text_help(char *s, int n)
{
	int		k;
	int		i;
	char	*t;

	k = 3;
	while (s[k] == ' ' && s[k] != '\0')
		k++;
	if (s[k] == '\0')
		error_exit(1);
	t = ft_substr(s, k, n - k);
	i = ft_strlen(t);
	k = 0;
	while (k < i)
	{
		if (t[k] == ' ')
			t[k] = '\0';
		k++;
	}
	return (t);
}

char	*read_text_help_s(char *s, int n)
{
	int		k;
	int		i;
	char	*t;

	k = 2;
	while (s[k] == ' ' && s[k] != '\0')
		k++;
	if (s[k] == '\0')
		error_exit(1);
	t = ft_substr(s, k, n - k);
	i = ft_strlen(t);
	k = 0;
	while (k < i)
	{
		if (t[k] == ' ')
			t[k] = '\0';
		k++;
	}
	return (t);
}

void	read_texture(char **map, t_params *p, int n)
{
	int		i;

	i = 0;
	while (i++ < n)
	{
		if (map[i][0] == 'N' && map[i][1] == 'O')
			p->tex[0].fn = read_text_help(map[i], ft_strlen(map[i]));
		else if (map[i][0] == 'S' && map[i][1] == 'O')
			p->tex[1].fn = read_text_help(map[i], ft_strlen(map[i]));
		else if (map[i][0] == 'W' && map[i][1] == 'E')
			p->tex[2].fn = read_text_help(map[i], ft_strlen(map[i]));
		else if (map[i][0] == 'E' && map[i][1] == 'A')
			p->tex[3].fn = read_text_help(map[i], ft_strlen(map[i]));
		else if (map[i][0] == 'S' && map[i][1] == ' ')
			p->tex[4].fn = read_text_help_s(map[i], ft_strlen(map[i]));
		else if (map[i][0] == 'F' && map[i][1] == ' ')
			p->cf = read_color(map[i]);
		else if (map[i][0] == 'C' && map[i][1] == ' ')
			p->cl = read_color(map[i]);
		else if (map[i][0] != ' ' && map[i][0] != '\0' && map[i][0] != 'R')
			error_exit(1);
	}
	if (p->tex[0].fn == NULL || p->tex[1].fn == NULL || p->tex[2].fn == NULL \
	|| p->tex[3].fn == NULL || p->tex[4].fn == NULL)
		error_exit(1);
}
