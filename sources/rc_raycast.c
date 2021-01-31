/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:45 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/17 20:15:56 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		rc_init(t_rc *rc, t_conf *conf)
{
	rc->map_x = (int)conf->pos_x;
	rc->map_y = (int)conf->pos_y;
	rc->d_dist_x = fabs(1 / rc->raydir_x);
	rc->d_dist_y = fabs(1 / rc->raydir_y);
	rc->hit = 0;
	if (rc->raydir_x < 0)
	{
		rc->step_x = -1;
		rc->s_dist_x = (conf->pos_x - rc->map_x) * rc->d_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->s_dist_x = (rc->map_x + 1.0 - conf->pos_x) * rc->d_dist_x;
	}
	if (rc->raydir_y < 0)
	{
		rc->step_y = -1;
		rc->s_dist_y = (conf->pos_y - rc->map_y) * rc->d_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->s_dist_y = (rc->map_y + 1.0 - conf->pos_y) * rc->d_dist_y;
	}
}

void		rc_dda_alg(t_rc *rc, t_conf *conf)
{
	while (rc->hit == 0)
	{
		if (rc->s_dist_x < rc->s_dist_y)
		{
			rc->s_dist_x += rc->d_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->s_dist_y += rc->d_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (conf->map[rc->map_y][rc->map_x] == '1')
			rc->hit = 1;
	}
}

void		rc_line(t_rc *rc, t_conf *conf)
{
	if (rc->side == 0)
	{
		rc->perp_wal_dist = (rc->map_x - conf->pos_x + (1 - rc->step_x) / 2);
		rc->perp_wal_dist /= rc->raydir_x;
	}
	else
	{
		rc->perp_wal_dist = (rc->map_y - conf->pos_y + (1 - rc->step_y) / 2);
		rc->perp_wal_dist /= rc->raydir_y;
	}
	rc->line_hgt = (int)(conf->height / rc->perp_wal_dist);
	rc->drw_strt = (-rc->line_hgt + conf->height) / 2;
	if (rc->drw_strt < 0)
		rc->drw_strt = 0;
	rc->drw_end = (rc->line_hgt + conf->height) / 2;
	if (rc->drw_end >= conf->height)
		rc->drw_end = conf->height - 1;
}

void		draw_fl_and_ceil(t_rc *rc, t_conf *conf)
{
	int y;

	y = 0;
	while (y < rc->drw_strt)
	{
		my_mlx_pixel_put(&conf->data, rc->x, y, conf->ceil_cl);
		y++;
	}
	y = rc->drw_end;
	while (y < conf->height)
	{
		my_mlx_pixel_put(&conf->data, rc->x, y, conf->floor_cl);
		y++;
	}
}

void		raycasting(t_conf *conf)
{
	double	*z_buff;
	t_rc	rc;

	rc.x = 0;
	z_buff = (double*)malloc(sizeof(double) * conf->width);
	while (rc.x < conf->width)
	{
		rc.camera_x = 2 * rc.x / (double)conf->width - 1;
		rc.raydir_x = conf->dir_x + conf->plx * rc.camera_x;
		rc.raydir_y = conf->dir_y + conf->ply * rc.camera_x;
		rc_init(&rc, conf);
		rc_dda_alg(&rc, conf);
		rc_line(&rc, conf);
		rc_tex_x(&rc, conf, conf->tex);
		rc_tex_step(&rc, conf->tex);
		rc_walls(&rc, conf, conf->tex);
		draw_fl_and_ceil(&rc, conf);
		z_buff[rc.x] = rc.perp_wal_dist;
		rc.x++;
	}
	sprite_cast(conf, z_buff, conf->tex[4]);
	free(z_buff);
}
