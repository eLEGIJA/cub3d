/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:41 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:24:41 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LOWBITS ((unsigned long)-1 / (unsigned char)-1)
#define HIGHBITS (LOWBITS << 7)

static void				*mod_memchr(const unsigned char *ch, int c, size_t n)
{
	while (n && *ch != (unsigned char)c)
	{
		ch++;
		n--;
	}
	return ((void *)(n == 0 ? NULL : ch));
}

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ch = s;
	const unsigned long	*long_ch;
	const unsigned long	long_c = (unsigned char)c * LOWBITS;

	if (!n)
		return (0);
	while (n && ((unsigned long)ch & (sizeof(long) - 1)) != 0)
	{
		if (*ch == (unsigned char)c)
			return ((void *)ch);
		ch++;
		n--;
	}
	long_ch = (unsigned long*)ch;
	while ((n > sizeof(long)) && ((((*long_ch ^ long_c) - LOWBITS)\
	& ~(*long_ch ^ long_c) & HIGHBITS) == 0))
	{
		n = n - sizeof(long);
		long_ch++;
	}
	ch = (unsigned char*)long_ch;
	return (mod_memchr(ch, c, n));
}
