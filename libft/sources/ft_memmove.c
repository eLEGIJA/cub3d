/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 17:32:27 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:24:30 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dest, const void *src, size_t length)
{
	unsigned char		*copy1;
	const unsigned char	*copy2;
	size_t				i;

	copy1 = (unsigned char *)dest;
	copy2 = (unsigned char *)src;
	i = 0;
	if (copy1 == NULL && copy2 == NULL)
		return (NULL);
	if (copy1 > copy2)
		while (i++ < length)
			copy1[length - i] = copy2[length - i];
	else
		while (length-- > 0)
			*(copy1++) = *(copy2++);
	return (dest);
}
