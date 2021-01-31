/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:51 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/17 20:15:14 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		srt_sprites(t_conf *conf, int *sprt_ord, double *sprt_dst)
{
	int		i;

	i = 0;
	while (i < conf->num_sprs)
	{
		sprt_ord[i] = i;
		sprt_dst[i] = pow((conf->pos_x - conf->sprite[i].x), 2);
		sprt_dst[i] += pow((conf->pos_y - conf->sprite[i].y), 2);
		i++;
	}
	ft_sort(sprt_ord, sprt_dst, conf->num_sprs);
}

void		mtrx_trans(t_conf *conf, t_sc *sc, int *sprt_ord, int i)
{
	sc->x = conf->sprite[sprt_ord[i]].x - conf->pos_x;
	sc->y = conf->sprite[sprt_ord[i]].y - conf->pos_y;
	sc->inv_det = 1.0 / (conf->plx * conf->dir_y - conf->dir_x * conf->ply);
	sc->trans_x = sc->inv_det * (conf->dir_y * sc->x - conf->dir_x * sc->y);
	sc->trans_y = sc->inv_det * (-conf->ply * sc->x + conf->plx * sc->y);
	sc->screen_x = (int)((conf->width / 2) * (1 + sc->trans_x / sc->trans_y));
	sc->height = abs((int)(conf->height / (sc->trans_y)));
}

void		tex_spr(t_conf *conf, t_sc *sc)
{
	sc->draw_start_y = -sc->height / 2 + conf->height / 2;
	if (sc->draw_start_y < 0)
		sc->draw_start_y = 0;
	sc->draw_end_y = sc->height / 2 + conf->height / 2;
	if (sc->draw_end_y >= conf->height)
		sc->draw_end_y = conf->height - 1;
	sc->width = abs((int)(conf->height / sc->trans_y));
	sc->draw_start_x = -sc->width / 2 + sc->screen_x;
	if (sc->draw_start_x < 0)
		sc->draw_start_x = 0;
	sc->draw_end_x = sc->width / 2 + sc->screen_x;
	if (sc->draw_end_x >= conf->width)
		sc->draw_end_x = conf->width - 1;
}

void		draw_sprite(t_sc *sc, t_conf *conf, double *zbuff, t_tex tex)
{
	int		xy[2];
	int		d;
	int		color;

	xy[0] = sc->draw_start_x;
	while (xy[0] < sc->draw_end_x)
	{
		xy[1] = sc->draw_start_y;
		sc->tex_x = (int)256 * (xy[0] - (-sc->width / 2 + sc->screen_x));
		sc->tex_x = sc->tex_x * tex.width / sc->width / 256;
		if (sc->trans_y > 0 && xy[0] > 0 && xy[0] < conf->width\
			&& sc->trans_y < zbuff[xy[0]])
		{
			while (xy[1] < sc->draw_end_y)
			{
				d = (xy[1]) * 256 - conf->height * 128 + sc->height * 128;
				sc->tex_y = ((d * tex.height) / sc->height) / 256;
				color = tex.addr[tex.width * sc->tex_y + sc->tex_x];
				if (color != -0x1000000)
					my_mlx_pixel_put(&conf->data, xy[0], xy[1], color);
				xy[1]++;
			}
		}
		xy[0]++;
	}
}

void		sprite_cast(t_conf *conf, double *z_buff, t_tex tex)
{
	t_sc	sc;
	int		*sprt_ord;
	double	*sprt_dst;
	int		i;

	i = 0;
	if (!(sprt_ord = malloc(sizeof(int) * conf->num_sprs)))
		ft_error(conf, 0, 0, 0);
	if (!(sprt_dst = malloc(sizeof(double) * conf->num_sprs)))
		ft_error(conf, 0, 0, 0);
	srt_sprites(conf, sprt_ord, sprt_dst);
	while (i < conf->num_sprs)
	{
		mtrx_trans(conf, &sc, sprt_ord, i);
		tex_spr(conf, &sc);
		draw_sprite(&sc, conf, z_buff, tex);
		i++;
	}
	free(sprt_ord);
	free(sprt_dst);
}
