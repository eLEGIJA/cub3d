/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:32 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/10 18:49:12 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_dir_we(int i, int j, t_conf *conf)
{
	if (conf->map[i][j] == 'W')
	{
		conf->dir_x = -1;
		conf->dir_y = 0;
		conf->plx = 0;
		conf->ply = -1;
	}
	else if (conf->map[i][j] == 'E')
	{
		conf->dir_x = 1;
		conf->dir_y = 0;
		conf->plx = 0;
		conf->ply = 1;
	}
}

static void	check_dir_ns(int i, int j, t_conf *conf)
{
	if (conf->map[i][j] == 'N')
	{
		conf->dir_x = 0;
		conf->dir_y = -1;
		conf->plx = 1;
		conf->ply = 0;
	}
	else if (conf->map[i][j] == 'S')
	{
		conf->dir_x = 0;
		conf->dir_y = 1;
		conf->plx = -1;
		conf->ply = 0;
	}
}

void		check_pos(t_conf *conf, int i, int j)
{
	conf->pos_x = j + 0.5;
	conf->pos_y = i + 0.5;
	if (conf->spawns < 1)
		conf->spawns++;
	else
		conf->error = 4;
	if (conf->map[i][j] == 'N' || conf->map[i][j] == 'S')
		check_dir_ns(i, j, conf);
	if (conf->map[i][j] == 'E' || conf->map[i][j] == 'W')
		check_dir_we(i, j, conf);
	conf->map[i][j] = '0';
}
