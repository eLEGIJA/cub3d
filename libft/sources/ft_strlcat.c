/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:26:18 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:26:18 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	size_t	dlen;

	d = dst;
	dlen = ft_strlen(dst);
	if (dlen >= size)
		return (size + ft_strlen(src));
	d = ft_memccpy(dst + dlen, src, '\0', size - dlen);
	if (!d)
		*(dst + size - 1) = '\0';
	return (ft_strlen(src) + dlen);
}
