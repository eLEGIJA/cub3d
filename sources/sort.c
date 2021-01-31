/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elegija <elegija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 06:34:24 by elegija           #+#    #+#             */
/*   Updated: 2021/01/31 06:39:10 by elegija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort(int *sprite_queue, double *sprite_dest, int i, int *check)
{
	double	buff;

	if (sprite_dest[i] < sprite_dest[i + 1])
	{
		*check = 1;
		buff = sprite_dest[i];
		sprite_dest[i] = sprite_dest[i + 1];
		sprite_dest[i + 1] = buff;
		buff = sprite_queue[i];
		sprite_queue[i] = sprite_queue[i + 1];
		sprite_queue[i + 1] = buff;
	}
}

void		ft_sort(int *sprite_queue, double *sprite_dest, int amount)
{
	int		i;
	int		check;

	check = 1;
	while (check)
	{
		i = 0;
		check = 0;
		while (i < amount - 1)
		{
			sort(sprite_queue, sprite_dest, i, &check);
			i++;
		}
	}
}
