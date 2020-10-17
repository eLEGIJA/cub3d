/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:45:04 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/17 20:18:40 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_sort(int *sprite_queue, double *sprite_dest, int amount)
{
	double	buff;
	int		i;
	int		check;

	check = 1;
	while (check)
	{
		i = 0;
		check = 0;
		while (i < amount - 1)
		{
			if (sprite_dest[i] < sprite_dest[i + 1])
			{
				check = 1;
				buff = sprite_dest[i];
				sprite_dest[i] = sprite_dest[i + 1];
				sprite_dest[i + 1] = buff;
				buff = sprite_queue[i];
				sprite_queue[i] = sprite_queue[i + 1];
				sprite_queue[i + 1] = buff;
			}
			i++;
		}
	}
}

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->l_len + x * (data->bpp / 8));
	*(unsigned int*)dest = color;
}

void		code_error(t_conf *conf)
{
	if (conf->error == 1)
		write(2, "Not valid resolution\n", 22);
	else if (conf->error == 2)
		write(2, "Not valid color\n", 17);
	else if (conf->error == 3)
		write(2, "Not valid path\n", 16);
	else if (conf->error == 4)
		write(2, "Not valid map\n", 15);
	else if (conf->error == 5)
		write(2, "Not valid texture\n", 19);
	else if (conf->error == 6)
		write(2, "Not valid extension\n", 21);
	else if (conf->error == 7)
		write(2, "Cannot open file\n", 17);
	else if (conf->error == 8)
		write(2, "Program flag error\n", 20);
	else if (conf->error == 9)
		write(2, "File has bad symbols\n", 22);
	else
		write(2, "Other error\n", 13);
}

void		nval(t_conf *conf, int error)
{
	conf->error = error;
	ft_error(conf, 0, 0, 0);
}

int			ft_close(t_conf *conf)
{
	if (conf->data.img)
		mlx_destroy_image(conf->mlx, conf->data.img);
	if (conf->no)
		free(conf->no);
	if (conf->so)
		free(conf->so);
	if (conf->we)
		free(conf->we);
	if (conf->ea)
		free(conf->ea);
	if (conf->sprt)
		free(conf->sprt);
	if (conf->map)
		free_split(conf->map);
	if (conf->sprite)
		free(conf->sprite);
	exit(0);
}
