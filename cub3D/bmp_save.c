/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:41:46 by aantonin          #+#    #+#             */
/*   Updated: 2021/02/27 12:58:43 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_save_bmp1(t_player pl, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = pl.p.res_w * pl.p.res_h * 4 + 54;
	header[2] = (unsigned char)(n);
	header[3] = (unsigned char)(n >> 8);
	header[4] = (unsigned char)(n >> 16);
	header[5] = (unsigned char)(n >> 24);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void	ft_save_bmp2(t_player pl, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = pl.p.res_w;
	header[4] = (unsigned char)(n);
	header[5] = (unsigned char)(n >> 8);
	header[6] = (unsigned char)(n >> 16);
	header[7] = (unsigned char)(n >> 24);
	n = pl.p.res_h;
	header[8] = (unsigned char)(n);
	header[9] = (unsigned char)(n >> 8);
	header[10] = (unsigned char)(n >> 16);
	header[11] = (unsigned char)(n >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_save_draw(t_player pl, int fd)
{
	int		i;
	char	*img;

	i = pl.p.res_h;
	img = pl.img_str.addr;
	while (--i)
		img += pl.img_str.line_length;
	while (i < pl.p.res_h)
	{
		write(fd, img, pl.p.res_w * 4);
		img -= pl.img_str.line_length;
		i++;
	}
}

void	bmp_save(t_player player)
{
	int fd;

	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_save_bmp1(player, fd);
	ft_save_bmp2(player, fd);
	ft_save_draw(player, fd);
	close(fd);
	exit(0);
}
