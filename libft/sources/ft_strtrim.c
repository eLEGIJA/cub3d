/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 21:28:39 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 16:52:15 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *str, char const *set)
{
	size_t	end;
	char	*new;

	if (!str)
		return (NULL);
	if (!set)
		return (ft_strdup(str));
	while (*str && ft_strchr(set, *str))
		str++;
	end = ft_strlen(str);
	while (end && ft_strchr(set, str[end]))
		end--;
	new = ft_substr((char*)str, 0, end + 1);
	return (new);
}
