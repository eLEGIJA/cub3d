/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elegija <elegija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:43:54 by msafflow          #+#    #+#             */
/*   Updated: 2021/01/31 02:00:47 by elegija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

int					my_get_color(t_conf *data, int x, int y)
{
	char			*dest;

	dest = data->data.addr + (y * data->data.l_len
		+ x * (data->data.bpp / 8));
	return (*(unsigned int*)dest);
}

static void			init_header(unsigned char *mas_heder, int size, t_conf *cfg)
{
	mas_heder[0] = (unsigned char)'B';
	mas_heder[1] = (unsigned char)'M';
	mas_heder[2] = (unsigned char)size;
	mas_heder[3] = (unsigned char)(size >> 8);
	mas_heder[4] = (unsigned char)(size >> 16);
	mas_heder[5] = (unsigned char)(size >> 24);
	mas_heder[10] = (unsigned char)54;
	mas_heder[14] = (unsigned char)40;
	mas_heder[18] = (unsigned char)cfg->width;
	mas_heder[19] = (unsigned char)(cfg->width >> 8);
	mas_heder[20] = (unsigned char)(cfg->width >> 16);
	mas_heder[21] = (unsigned char)(cfg->width >> 24);
	mas_heder[22] = (unsigned char)cfg->height;
	mas_heder[23] = (unsigned char)(cfg->height >> 8);
	mas_heder[24] = (unsigned char)(cfg->height >> 16);
	mas_heder[25] = (unsigned char)(cfg->height >> 24);
	mas_heder[26] = (unsigned char)1;
	mas_heder[28] = (unsigned char)24;
}

static void			ft_scrnsht_cfg(t_conf *cfg)
{
	if (cfg->width % 4)
		cfg->width = cfg->width - (cfg->width % 4);
	cfg->data.img = mlx_new_image(cfg->mlx,
		cfg->width, cfg->height);
	cfg->data.addr = mlx_get_data_addr(cfg->data.img,
		&cfg->data.bpp, &cfg->data.l_len, &cfg->data.enan);
	tex_init(cfg->tex, cfg);
	raycasting(cfg);
}

static void			put_img_skrin(t_conf *cfg, int fd)
{
	int				color;
	int				x;
	int				y;
	int				size_x;

	color = 0;
	x = 0;
	y = cfg->height - 1;
	size_x = cfg->width;
	while (y >= 0)
	{
		while (x < size_x)
		{
			color = my_get_color(cfg, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
		x = 0;
	}
}

void				ft_bitmap(t_conf *cfg)
{
	int				fd;
	unsigned char	mas_header[54];
	int				count;
	int				size;

	ft_scrnsht_cfg(cfg);
	size = cfg->width * cfg->height + 54;
	count = 0;
	if (!(fd = open("./screenshot.bmp", O_RDWR | O_CREAT, 0666)))
		ft_error(cfg, 0, 0, 0);
	while (count < 54)
		mas_header[count++] = (unsigned char)0;
	init_header(mas_header, size, cfg);
	write(fd, mas_header, 54);
	put_img_skrin(cfg, fd);
	close(fd);
	exit(0);
}
