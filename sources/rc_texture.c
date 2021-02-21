/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:57 by msafflow          #+#    #+#             */
/*   Updated: 2021/02/21 11:08:37 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rc_tex_x_utils(t_rc *rc, t_tex *tex)
{
	if (rc->side == 0)
	{
		if (rc->step_x < 0)
			rc->tex_x = (int)(rc->wl_x * (double)(tex[0].width));
		else
			rc->tex_x = (int)(rc->wl_x * (double)(tex[1].width));
	}
	else
	{
		if (rc->step_y < 0)
			rc->tex_x = (int)(rc->wl_x * (double)(tex[2].width));
		else
			rc->tex_x = (int)(rc->wl_x * (double)(tex[3].width));
	}
}

void		rc_tex_x(t_rc *rc, t_conf *conf, t_tex *tex)
{
	if (rc->side == 0)
		rc->wl_x = conf->pos_y + rc->perp_wal_dist * rc->raydir_y;
	else
		rc->wl_x = conf->pos_x + rc->perp_wal_dist * rc->raydir_x;
	rc->wl_x -= (int)rc->wl_x;
	rc_tex_x_utils(rc, tex);
}

void		rc_tex_step(t_rc *rc, t_tex *tex)
{
	if (rc->side == 0)
	{
		if (rc->step_x < 0)
		{
			rc->step = 1.0 * tex[0].height / rc->line_hgt;
			rc->tex_x = tex->height - rc->tex_x - 1;
		}
		else
			rc->step = 1.0 * tex[1].height / rc->line_hgt;
	}
	else
	{
		if (rc->step_y < 0)
			rc->step = 1.0 * tex[2].height / rc->line_hgt;
		else
		{
			rc->step = 1.0 * tex[3].height / rc->line_hgt;
			rc->tex_x = tex->height - rc->tex_x - 1;
		}
	}
}
