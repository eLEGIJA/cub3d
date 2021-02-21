/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_texture_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:08:32 by msafflow          #+#    #+#             */
/*   Updated: 2021/02/21 11:08:34 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		rc_paint_walls(t_rc *rc, t_conf *conf, t_tex tex)
{
	int		color;
	int		tex_y;

	tex_y = (int)rc->tex_pos & (tex.height - 1);
	color = tex.addr[tex.height * tex_y + rc->tex_x];
	my_mlx_pixel_put(&conf->data, rc->x, rc->y, color);
}

void		rc_walls(t_rc *rc, t_conf *conf, t_tex *tx)
{
	rc->y = rc->drw_strt;
	rc[0].tex_pos = (rc->drw_strt - (conf->height + rc->line_hgt) / 2)\
		* rc->step;
	while (rc->y < rc->drw_end)
	{
		rc->tex_pos += rc->step;
		if (rc->side != 0)
		{
			if (rc->step_y < 0)
				rc_paint_walls(rc, conf, tx[2]);
			else
				rc_paint_walls(rc, conf, tx[3]);
		}
		else
		{
			if (rc->step_x < 0)
				rc_paint_walls(rc, conf, tx[0]);
			else
				rc_paint_walls(rc, conf, tx[1]);
		}
		rc->y++;
	}
}

void		tex_init(t_tex *tex, t_conf *conf)
{
	if (!(tex[4].img = mlx_xpm_file_to_image(conf->mlx,
		conf->sprt, &tex[4].width, &tex[4].height)))
		nval(conf, 5);
	if (!(tex[2].img = mlx_xpm_file_to_image(conf->mlx,
		conf->no, &tex[2].width, &tex[2].height)))
		nval(conf, 5);
	if (!(tex[0].img = mlx_xpm_file_to_image(conf->mlx,
		conf->we, &tex[0].width, &tex[0].height)))
		nval(conf, 5);
	if (!(tex[3].img = mlx_xpm_file_to_image(conf->mlx,
		conf->so, &tex[3].width, &tex[3].height)))
		nval(conf, 5);
	if (!(tex[1].img = mlx_xpm_file_to_image(conf->mlx,
		conf->ea, &tex[1].width, &tex[1].height)))
		nval(conf, 5);
	tex[3].addr = (int*)mlx_get_data_addr(tex[3].img,
		&tex[3].bpp, &tex[3].l_len, &tex[3].enan);
	tex[4].addr = (int*)mlx_get_data_addr(tex[4].img,
		&tex[4].bpp, &tex[4].l_len, &tex[4].enan);
	tex[0].addr = (int*)mlx_get_data_addr(tex[0].img,
		&tex[0].bpp, &tex[0].l_len, &tex[0].enan);
	tex[1].addr = (int*)mlx_get_data_addr(tex[1].img,
		&tex[1].bpp, &tex[1].l_len, &tex[1].enan);
	tex[2].addr = (int*)mlx_get_data_addr(tex[2].img,
		&tex[2].bpp, &tex[2].l_len, &tex[2].enan);
}
