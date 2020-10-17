/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:58 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:24:58 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LOWBITS ((unsigned long)-1 / (unsigned char)-1)

void					*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*ch;
	unsigned long		*long_ch;
	const unsigned long	long_c = (unsigned char)c * LOWBITS;

	ch = s;
	long_ch = (unsigned long*)ch;
	while (n && ((unsigned long)ch & (sizeof(long) - 1)) != 0)
	{
		if (*ch == '\0')
			return (s);
		*(ch)++ = c;
		n--;
	}
	while (n > sizeof(long))
	{
		*long_ch++ = long_c;
		n -= sizeof(long);
	}
	ch = (unsigned char*)long_ch;
	while (n--)
		*ch++ = (unsigned char)c;
	return (s);
}
