/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:26:23 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:26:23 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*d;

	if (!dst || !src)
		return (0);
	d = dst;
	if (size != 0)
		d = ft_memccpy(dst, src, '\0', size - 1);
	if (!d && size != 0)
		*(dst + size - 1) = '\0';
	return (ft_strlen(src));
}
