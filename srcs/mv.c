/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:06 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/17 20:25:12 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		right(t_game *game)
{
	double	old_dir_x;
	double	old_pl_x;

	old_dir_x = game->conf.dir_x;
	game->conf.dir_x = game->conf.dir_x * cos(ROTATE)
		- game->conf.dir_y * sin(ROTATE);
	game->conf.dir_y = old_dir_x * sin(ROTATE)
		+ game->conf.dir_y * cos(ROTATE);
	old_pl_x = game->conf.plx;
	game->conf.plx = game->conf.plx * cos(ROTATE)
		- game->conf.ply * sin(ROTATE);
	game->conf.ply = old_pl_x * sin(ROTATE) + game->conf.ply * cos(ROTATE);
}

void		left(t_game *game)
{
	double	old_dir_x;
	double	old_pl_x;

	old_dir_x = game->conf.dir_x;
	game->conf.dir_x = game->conf.dir_x * cos(-ROTATE)
		- game->conf.dir_y * sin(-ROTATE);
	game->conf.dir_y = old_dir_x * sin(-ROTATE)
		+ game->conf.dir_y * cos(-ROTATE);
	old_pl_x = game->conf.plx;
	game->conf.plx = game->conf.plx * cos(-ROTATE)
		- game->conf.ply * sin(-ROTATE);
	game->conf.ply = old_pl_x * sin(-ROTATE) + game->conf.ply * cos(-ROTATE);
}

void		forward_back(t_game *game)
{
	double	pos_x;
	double	pos_y;

	if (game->w)
	{
		pos_x = game->conf.pos_x + game->conf.dir_x * MOVEMENT;
		pos_y = game->conf.pos_y + game->conf.dir_y * MOVEMENT;
		if (game->conf.map[(int)(game->conf.pos_y)][(int)(pos_x + F)] == '0' &&
			game->conf.map[(int)(game->conf.pos_y)][(int)(pos_x - 0.01)] == '0')
			game->conf.pos_x += game->conf.dir_x * MOVEMENT;
		if (game->conf.map[(int)(pos_y + F)][(int)(game->conf.pos_x)] == '0' &&
			game->conf.map[(int)(pos_y - 0.01)][(int)(game->conf.pos_x)] == '0')
			game->conf.pos_y += game->conf.dir_y * MOVEMENT;
	}
	if (game->s)
	{
		pos_x = game->conf.pos_x - game->conf.dir_x * MOVEMENT;
		pos_y = game->conf.pos_y - game->conf.dir_y * MOVEMENT;
		if (game->conf.map[(int)(game->conf.pos_y)][(int)(pos_x + F)] == '0' &&
			game->conf.map[(int)(game->conf.pos_y)][(int)(pos_x - 0.01)] == '0')
			game->conf.pos_x -= game->conf.dir_x * MOVEMENT;
		if (game->conf.map[(int)(pos_y + F)][(int)(game->conf.pos_x)] == '0' &&
			game->conf.map[(int)(pos_y - 0.01)][(int)(game->conf.pos_x)] == '0')
			game->conf.pos_y -= game->conf.dir_y * MOVEMENT;
	}
}

void		left_and_right(t_game *game)
{
	double	pos_x;
	double	pos_y;

	if (game->d)
	{
		pos_x = game->conf.pos_x - game->conf.dir_y * MOVEMENT;
		pos_y = game->conf.pos_y + game->conf.dir_x * MOVEMENT;
		if (game->conf.map[(int)(game->conf.pos_y)][(int)(pos_x + F)] == '0' &&
			game->conf.map[(int)(game->conf.pos_y)][(int)(pos_x - 0.01)] == '0')
			game->conf.pos_x -= game->conf.dir_y * MOVEMENT;
		if (game->conf.map[(int)(pos_y + F)][(int)(game->conf.pos_x)] == '0' &&
			game->conf.map[(int)(pos_y - 0.01)][(int)(game->conf.pos_x)] == '0')
			game->conf.pos_y += game->conf.dir_x * MOVEMENT;
	}
	if (game->a)
	{
		pos_x = game->conf.pos_x + game->conf.dir_y * MOVEMENT;
		pos_y = game->conf.pos_y - game->conf.dir_x * MOVEMENT;
		if (game->conf.map[(int)(game->conf.pos_y)][(int)(pos_x + F)] == '0' &&
			game->conf.map[(int)(game->conf.pos_y)][(int)(pos_x - 0.01)] == '0')
			game->conf.pos_x += game->conf.dir_y * MOVEMENT;
		if (game->conf.map[(int)(pos_y + F)][(int)(game->conf.pos_x)] == '0' &&
			game->conf.map[(int)(pos_y - 0.01)][(int)(game->conf.pos_x)] == '0')
			game->conf.pos_y -= game->conf.dir_x * MOVEMENT;
	}
}

void		check_state(t_game *game)
{
	if (game->left)
		left(game);
	if (game->right)
		right(game);
	if (game->w || game->s)
		forward_back(game);
	if (game->a || game->d)
		left_and_right(game);
}
