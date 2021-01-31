/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:26:41 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:26:41 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *bg, const char *ltle, size_t len)
{
	size_t		ltle_len;

	ltle_len = ft_strlen(ltle);
	if (!ltle[0])
		return ((char*)bg);
	while (*bg && ltle_len <= len--)
	{
		if (*bg == *ltle && !ft_strncmp(bg, ltle, ltle_len))
			return ((char *)bg);
		bg++;
	}
	return (0);
}
