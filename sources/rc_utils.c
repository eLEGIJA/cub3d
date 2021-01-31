/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elegija <elegija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:45:04 by msafflow          #+#    #+#             */
/*   Updated: 2021/01/31 06:34:37 by elegija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->l_len + x * (data->bpp / 8));
	*(unsigned int*)dest = color;
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
