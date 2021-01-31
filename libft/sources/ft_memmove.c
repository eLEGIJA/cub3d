/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:54 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:24:54 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LOWBITS ((unsigned long)-1 / (unsigned char)-1)
#define HIGHBITS (LOWBITS << 7)

static void				*ft_memrcpy(void *dst, const void *src, size_t n)
{
	unsigned long		*long_dst;
	const unsigned long	*long_src;
	unsigned char		*mod_dst;
	const unsigned char	*mod_src = (unsigned char*)src + n - 1;

	mod_dst = (unsigned char*)dst + n - 1;
	while (n && ((unsigned long)mod_dst & (sizeof(long) - 1)) != 0)
	{
		*mod_dst-- = *mod_src--;
		n--;
	}
	long_dst = (unsigned long*)(mod_dst + 1);
	long_src = (const unsigned long*)(mod_src + 1);
	while (n > sizeof(long))
	{
		*(--long_dst) = *(--long_src);
		n = n - sizeof(long);
	}
	mod_dst = (unsigned char*)long_dst - 1;
	mod_src = (const unsigned char*)long_src - 1;
	while (n--)
		*mod_dst-- = *mod_src--;
	return (dst);
}

void					*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	if (dst > src)
		return (ft_memrcpy(dst, src, n));
	return (0);
}
