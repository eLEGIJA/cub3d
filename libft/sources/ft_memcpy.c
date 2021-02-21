/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:16:55 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:18:05 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	new_dest = dest;
	new_src = (unsigned char *)src;
	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i++ < n)
		*new_dest++ = *new_src++;
	return (dest);
}
