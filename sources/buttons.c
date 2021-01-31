/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elegija <elegija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:43:47 by msafflow          #+#    #+#             */
/*   Updated: 2021/01/31 06:43:22 by elegija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			key_press(int key, t_game *game)
{
	if (key == 53)
		ft_close(&game->conf);
	if (key == kVK_ANSI_W)
		game->w = 1;
	if (key == kVK_ANSI_S)
		game->s = 1;
	if (key == kVK_LeftArrow)
		game->left = 1;
	if (key == kVK_RightArrow)
		game->right = 1;
	if (key == kVK_ANSI_A)
		game->a = 1;
	if (key == kVK_ANSI_D)
		game->d = 1;
	if (game->left == 1 && game->right == 1)
	{
		game->left = 0;
		game->right = 0;
	}
	return (0);
}

int			key_unpress(int key, t_game *game)
{
	if (key == kVK_ANSI_W)
		game->w = 0;
	if (key == kVK_ANSI_S)
		game->s = 0;
	if (key == kVK_LeftArrow)
		game->left = 0;
	if (key == kVK_RightArrow)
		game->right = 0;
	if (key == kVK_ANSI_A)
		game->a = 0;
	if (key == kVK_ANSI_D)
		game->d = 0;
	return (0);
}
