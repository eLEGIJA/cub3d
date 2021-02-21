/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:28:14 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 16:58:57 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*last;
	size_t	i;

	last = (char *)s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == (char)c)
			return (last + i);
		i--;
	}
	if (last[i] == (char)c)
		return (last);
	return (0);
}
