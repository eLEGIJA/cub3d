/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clr_and_res.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:12 by msafflow          #+#    #+#             */
/*   Updated: 2021/02/21 11:08:09 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_countchr(char *str, int c)
{
	int		i;
	char	*buff;

	i = 0;
	buff = str;
	while ((buff = ft_strchr(buff, c)))
	{
		i++;
		buff++;
	}
	return (i);
}

static int	check_colors(int shift, char *s_col)
{
	int		color;
	int		i;

	i = 0;
	if (!s_col)
		return (-1);
	while (s_col[i])
	{
		if (!(ft_memchr("0123456789", s_col[i], 11)))
			return (-1);
		i++;
	}
	color = ft_atoi(s_col);
	if (color > 255 || color < 0)
		return (-1);
	else
		return (color << shift);
}

int			ft_color(char **col_line, t_conf *conf, int *color)
{
	char	**colors;

	if (col_line[2])
		return (conf->error = 2);
	if ((ft_countchr(col_line[1], ',')) != 2)
		conf->error = 2;
	colors = ft_split(col_line[1], ',');
	if (*color != -1 || conf->ymp == 1 || !(colors))
		return (conf->error = 2);
	if (colors[3])
		conf->error = 2;
	*color = 0;
	*color = check_colors(16, colors[0]);
	if (*color == -1)
		conf->error = 2;
	*color = *color | check_colors(8, colors[1]);
	if (*color == -1)
		conf->error = 2;
	*color = *color | check_colors(0, colors[2]);
	if (*color == -1)
		conf->error = 2;
	free_split(colors);
	return (*color);
}

int			chk_res(char *res, t_conf *conf)
{
	int		i;

	i = 0;
	if (!res)
		return (conf->error = 1);
	while (res[i])
	{
		if (!(ft_memchr("0123456789", res[i], 11)))
			conf->error = 1;
		i++;
	}
	return (ft_atoi(res));
}

void		frame_res(char **spl_line, t_conf *conf)
{
	int		width;
	int		height;

	if (spl_line[3])
		conf->error = 1;
	if (conf->width != -1 || conf->height != -1 || conf->ymp == 1)
		conf->error = 1;
	mlx_get_screen_size(conf->mlx, &width, &height);
	conf->width = chk_res(spl_line[1], conf);
	if (conf->width > width)
		conf->width = width;
	if (conf->width < 100)
		conf->error = 1;
	conf->height = chk_res(spl_line[2], conf);
	if (conf->height > height)
		conf->height = height;
	if (conf->height < 100)
		conf->error = 1;
}
