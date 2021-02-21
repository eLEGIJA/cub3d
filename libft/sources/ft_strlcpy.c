/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 21:36:23 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:02:02 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcpy(char *dest, const char *src, size_t length)
{
	unsigned char	*copy1;
	unsigned char	*copy2;
	size_t			i;
	size_t			j;

	i = 0;
	copy1 = (unsigned char *)dest;
	copy2 = (unsigned char *)src;
	if (!copy1 && !copy2)
		return (0);
	while (copy2[i])
		i++;
	if (length == 0)
		return (i);
	j = 0;
	while (j + 1 < length && copy2[j])
	{
		copy1[j] = copy2[j];
		j++;
	}
	copy1[j] = '\0';
	return (i);
}
