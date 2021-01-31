/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:50 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:24:50 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long		*long_dst;
	const unsigned long	*long_src;
	unsigned char		*ch_dst;
	const unsigned char	*ch_src;
	unsigned long		i;

	if (!dst && !src)
		return (0);
	ch_dst = dst;
	ch_src = src;
	i = 0;
	while (i++ < n && ((unsigned long)dst & (sizeof(long) - 1)) != 0)
		*ch_dst++ = *ch_src++;
	long_dst = (unsigned long*)dst;
	long_src = (const unsigned long*)src;
	i = 0;
	while (i++ < (unsigned long)n / sizeof(long))
		*long_dst++ = *long_src++;
	ch_dst = (unsigned char*)long_dst;
	ch_src = (const unsigned char*)long_src;
	i = 0;
	while (i++ < (unsigned long)n % sizeof(long))
		*ch_dst++ = *ch_src++;
	return (dst);
}
