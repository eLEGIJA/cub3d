/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:19 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/17 20:17:18 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "cub3d.h"

void		check_path(t_conf *conf, char **line, char **s)
{
	if (line[2])
		conf->error = 3;
	if (line[1])
		check_tag(conf, line[1], ".xpm");
	if (conf->ymp == 1)
		conf->error = 6;
	if (!*s && line[1])
		*s = check_strdup(line[1], conf);
	else
		conf->error = -1;
}

void		chk_empty(t_conf *conf, t_list *lst)
{
	char	*str;
	int		i;

	str = ft_lstlast(lst)->content;
	i = 0;
	if (conf->ymp == 1)
	{
		while (str[i])
		{
			if (!(ft_memchr("1 ", str[i], 3)) && !(ft_strncmp("1", str, 2)))
				conf->error = 4;
			i++;
		}
		list_add(conf, lst, "  ");
	}
}

void		ft_flags(char **spl_line, char *line, t_list *lst, t_conf *conf)
{
	if (spl_line[0] == NULL)
		chk_empty(conf, lst);
	else if (!(ft_strncmp("R", spl_line[0], 2)))
		frame_res(spl_line, conf);
	else if (!(ft_strncmp("NO", spl_line[0], 3)))
		check_path(conf, spl_line, &conf->no);
	else if (!(ft_strncmp("SO", spl_line[0], 3)))
		check_path(conf, spl_line, &conf->so);
	else if (!(ft_strncmp("WE", spl_line[0], 3)))
		check_path(conf, spl_line, &conf->we);
	else if (!(ft_strncmp("EA", spl_line[0], 3)))
		check_path(conf, spl_line, &conf->ea);
	else if (!(ft_strncmp("S", spl_line[0], 2)))
		check_path(conf, spl_line, &conf->sprt);
	else if (!(ft_strncmp("F", spl_line[0], 2)))
		ft_color(spl_line, conf, &conf->floor_cl);
	else if (!(ft_strncmp("C", spl_line[0], 2)))
		ft_color(spl_line, conf, &conf->ceil_cl);
	else if ((!(ft_strncmp("0", spl_line[0], 1)) ||
	!(ft_strncmp("1", spl_line[0], 1))) && (conf->ymp = 1))
		list_add(conf, lst, line);
	else
		conf->error = 9;
}

void		read_line(char ***spl_line, char **line, t_conf *conf, t_list *lst)
{
	if (!(*spl_line = ft_split(*line, ' ')))
		ft_error(conf, lst, *line, *spl_line);
	ft_flags(*spl_line, *line, lst, conf);
	free(*line);
	*line = 0;
	free_split(*spl_line);
	*spl_line = 0;
}

void		parsing(char *file, t_conf *conf)
{
	t_list	*list;
	int		fd;
	char	*line;
	char	**split_line;

	if (conf->error)
		nval(conf, conf->error);
	list = ft_lstnew(0);
	if ((fd = open(file, O_RDONLY)) < 0)
		nval(conf, 7);
	while ((get_next_line(fd, &line)) > 0)
		read_line(&split_line, &line, conf, list);
	read_line(&split_line, &line, conf, list);
	map(list, conf, line, split_line);
}
