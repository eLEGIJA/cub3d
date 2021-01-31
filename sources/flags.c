/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elegija <elegija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 06:48:06 by elegija           #+#    #+#             */
/*   Updated: 2021/01/31 06:48:27 by elegija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_flags(char **spl_line, char *line, t_list *lst, t_conf *conf)
{
	if (spl_line[0] == NULL)
		chk_empty(conf, lst);
	else if (!(ft_strncmp("S", spl_line[0], 2)))
		check_path(conf, spl_line, &conf->sprt);
	else if (!(ft_strncmp("C", spl_line[0], 2)))
		ft_color(spl_line, conf, &conf->ceil_cl);
	else if (!(ft_strncmp("R", spl_line[0], 2)))
		frame_res(spl_line, conf);
	else if (!(ft_strncmp("WE", spl_line[0], 3)))
		check_path(conf, spl_line, &conf->we);
	else if (!(ft_strncmp("EA", spl_line[0], 3)))
		check_path(conf, spl_line, &conf->ea);
	else if (!(ft_strncmp("NO", spl_line[0], 3)))
		check_path(conf, spl_line, &conf->no);
	else if ((!(ft_strncmp("0", spl_line[0], 1)) || \
		!(ft_strncmp("1", spl_line[0], 1))) && (conf->ymp = 1))
		list_add(conf, lst, line);
	else if (!(ft_strncmp("SO", spl_line[0], 3)))
		check_path(conf, spl_line, &conf->so);
	else if (!(ft_strncmp("F", spl_line[0], 2)))
		ft_color(spl_line, conf, &conf->floor_cl);
	else
		conf->error = 9;
}
