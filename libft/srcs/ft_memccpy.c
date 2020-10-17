/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:34 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:24:34 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const void	*src2 = ft_memchr(src, c, n);

	if (n == 0)
		return (0);
	if (src2)
	{
		ft_memcpy(dst, src, src2 - src + 1);
		return (dst + (src2 - src + 1));
	}
	ft_memcpy(dst, src, n);
	return (0);
}
