/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:48:55 by aantonin          #+#    #+#             */
/*   Updated: 2021/03/05 16:27:51 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

t_params		params_nol(void)
{
	t_params	params;
	int			i;

	params.res_w = 0;
	params.res_h = 0;
	params.cf = 0;
	params.cl = 0;
	params.spr_coun = 0;
	i = 0;
	while (i < 5)
	{
		params.tex[i].addr = NULL;
		params.tex[i].width = 0;
		params.tex[i].height = 0;
		params.tex[i].img = NULL;
		params.tex[i].kh = 1;
		i++;
	}
	return (params);
}

void			read_res(char *r, t_params *p)
{
	int			i;

	i = 2;
	while (ft_isdigit(r[i]) != 1 && r[i] != '\0')
		i++;
	if (r[i] != '\0')
		p->res_w = ft_atoi(&r[i]);
	while (r[i] != ' ')
		i++;
	while (ft_isdigit(r[i]) != 1 && r[i] != '\0')
		i++;
	if (r[i] != '\0')
		p->res_h = ft_atoi(&r[i]);
	if (p->res_h == 0 && p->res_w == 0)
		error_exit(1);
}

void			check_color(t_color c)
{
	if (c.r < 0 || c.r > 255)
		error_exit(1);
	if (c.g < 0 || c.g > 255)
		error_exit(1);
	if (c.b < 0 || c.b > 255)
		error_exit(1);
}

int				read_color(char *m)
{
	int			i;
	t_color		c;
	int			c1;

	if (ft_isdigit(m[2]) == 1)
		c.r = ft_atoi(&m[2]);
	else
		error_exit(1);
	i = 2;
	while (m[i] != ',' && m[i] != '\0')
		i++;
	if (m[i] != '\0' && m[i + 1] != '\0')
		c.g = ft_atoi(&m[i + 1]);
	else
		error_exit(1);
	i++;
	while (m[i] != ',' && m[i] != '\0')
		i++;
	if (m[i] != '\0' && m[i + 1] != '\0')
		c.b = ft_atoi(&m[i + 1]);
	else
		error_exit(1);
	check_color(c);
	c1 = c.r * 256 * 256 + c.g * 256 + c.b;
	return (c1);
}
