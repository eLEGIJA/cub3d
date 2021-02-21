/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:28:24 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 00:22:03 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t pos;
	size_t i;

	if (!*str2)
		return ((char*)str1);
	pos = 0;
	while (str1[pos] != '\0' && pos < len)
	{
		if (str1[pos] == str2[0])
		{
			i = 1;
			while (str2[i] != '\0' && str1[pos + i] == str2[i] && \
			(pos + i) < len)
				++i;
			if (str2[i] == '\0')
				return ((char*)&str1[pos]);
		}
		++pos;
	}
	return (0);
}
