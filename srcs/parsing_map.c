/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:26 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/17 20:16:46 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_valid(int i, int j, t_conf *conf, int *spr)
{
	if (!(ft_memchr("NSWE 012", conf->map[i][j], 9)))
		conf->error = 1;
	if (ft_memchr("NSWE", conf->map[i][j], 5))
		check_pos(conf, i, j);
	if (conf->map[i][j] == '0')
	{
		if (conf->map[i + 1][j] == ' ' || conf->map[i][j + 1] == ' ' ||
			conf->map[i - 1][j] == ' ' || conf->map[i][j - 1] == ' ' ||
			conf->map[i + 1][j] == '\0' || conf->map[i][j + 1] == '\0' ||
			conf->map[i - 1][j] == '\0' || conf->map[i][j - 1] == '\0')
			conf->error = 4;
		if (((int)ft_strlen(conf->map[i - 1]) + 1 < j) ||
			((int)ft_strlen(conf->map[i + 1]) + 1 < j))
			conf->error = 4;
	}
	if (conf->map[i][j] == '2')
	{
		conf->sprite[*spr].x = j + 0.5;
		conf->sprite[*spr].y = i + 0.5;
		(*spr)++;
	}
}

static void	check_border_map(int i, t_conf *conf)
{
	int		j;

	j = 0;
	while ((conf->map[i]) && conf->map[i][j])
	{
		if (!(ft_memchr("1 ", conf->map[i][j], 3)))
			conf->error = 4;
		j++;
	}
	if (conf->height == -1 || conf->width == -1)
		conf->error = 1;
	if (conf->floor_cl == -1 || conf->ceil_cl == -1)
		conf->error = 2;
}

static int	ft_checkmap(t_conf *conf)
{
	int		i;
	int		j;
	int		spr;

	i = 1;
	j = 1;
	spr = 0;
	check_border_map(0, conf);
	while (i < conf->map_size - 1)
	{
		j = 1;
		if (!(ft_memchr("1 ", conf->map[i][0], 3)))
			return (conf->error = 4);
		while (conf->map[i][j + 1])
			check_valid(i, j++, conf, &spr);
		if (!(ft_memchr("1 ", conf->map[i][j], 3)))
			return (conf->error = 4);
		i++;
	}
	check_border_map(conf->map_size - 1, conf);
	if (!conf->spawns)
		conf->error = 4;
	return (0);
}

void		map(t_list *lst, t_conf *conf, char *line, char **spl_line)
{
	int		i;
	t_list	*fst_list;

	if (conf->error)
		ft_error(conf, lst, line, spl_line);
	fst_list = lst;
	conf->spawns = 0;
	lst = lst->next;
	i = 0;
	conf->map_size = ft_lstsize(lst);
	if (!(conf->map = (char**)malloc(sizeof(int*) * (conf->map_size + 1))))
		conf->error = 4;
	conf->map[conf->map_size] = NULL;
	conf->sprite = (t_sprite*)malloc(sizeof(t_sprite) * (conf->num_sprs + 1));
	while (i < conf->map_size)
	{
		conf->map[i++] = check_strdup((char*)lst->content, conf);
		lst = lst->next;
	}
	ft_checkmap(conf);
	if (conf->error)
		ft_error(conf, fst_list, line, spl_line);
	ft_lstclear(&fst_list, free);
}
