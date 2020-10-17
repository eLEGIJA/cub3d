/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:38 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/17 20:16:09 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_split(char **output)
{
	size_t	i;

	i = 0;
	while (output[i])
	{
		if (output[i])
			free(output[i]);
		i++;
	}
	free(output);
}

void		ft_error(t_conf *conf, t_list *lst, char *line, char **spl_line)
{
	write(2, "Error\n", 7);
	code_error(conf);
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
	if (lst)
		ft_lstclear(&lst, free);
	if (line)
		free(line);
	if (spl_line)
		free_split(spl_line);
	exit(0);
}

char		*check_strdup(const char *s, t_conf *conf)
{
	char	*new_str;

	if (!(new_str = ft_strdup(s)))
		conf->error = -1;
	return (new_str);
}

void		list_add(t_conf *conf, t_list *lst, char *line)
{
	char	*spr_line;
	char	*new_line;

	new_line = check_strdup(line, conf);
	ft_lstadd_back(&lst, ft_lstnew(new_line));
	spr_line = new_line;
	while ((spr_line = ft_strchr(spr_line++, '2')) && spr_line++)
		conf->num_sprs++;
}

void		check_tag(t_conf *conf, char *s, char *tag)
{
	s = ft_strrchr(s, tag[0]);
	if (!s || (ft_strncmp(s, tag, ft_strlen(s))))
		conf->error = 6;
}
