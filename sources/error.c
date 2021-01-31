/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elegija <elegija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 05:25:34 by elegija           #+#    #+#             */
/*   Updated: 2021/01/31 05:35:07 by elegija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void		ft_error(t_conf *conf, t_list *lst, char *line, char **spl_line)
{
	write(2, "Error\n", 7);
	code_error(conf);
	if (conf->no)
		free(conf->no);
	if (conf->sprt)
		free(conf->sprt);
	if (conf->so)
		free(conf->so);
	if (conf->we)
		free(conf->we);
	if (conf->ea)
		free(conf->ea);
	if (conf->sprite)
		free(conf->sprite);
	if (conf->map)
		free_split(conf->map);
	if (lst)
		ft_lstclear(&lst, free);
	if (line)
		free(line);
	if (spl_line)
		free_split(spl_line);
	exit(0);
}
