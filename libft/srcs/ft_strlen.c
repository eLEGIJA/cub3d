/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:26:27 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:26:27 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LOWBITS ((unsigned long)-1 / (unsigned char)-1)
#define HIGHBITS (LOWBITS << 7)

size_t						ft_strlen(const char *s)
{
	const unsigned char		*ch;
	unsigned long			oct_byte;

	ch = (unsigned char*)s;
	while (((unsigned long)ch & (sizeof(long) - 1)) != 0)
	{
		if (*ch == '\0')
			return ((size_t)ch - (size_t)s);
		ch++;
	}
	oct_byte = *((const unsigned long *)ch);
	while (((oct_byte - LOWBITS) & ~oct_byte & HIGHBITS) == 0)
	{
		ch = ch + sizeof(long);
		oct_byte = *((const unsigned long *)ch);
	}
	while (*ch)
		ch++;
	return ((size_t)ch - (size_t)s);
}
