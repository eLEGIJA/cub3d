/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 17:49:50 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:18:36 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t length)
{
	size_t			i;
	unsigned char	*copy1;
	unsigned char	*copy2;

	copy1 = (unsigned char*)dest;
	copy2 = (unsigned char*)src;
	i = 0;
	while (i < length)
	{
		copy1[i] = copy2[i];
		if (copy1[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		++i;
	}
	return (NULL);
}
