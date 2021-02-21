/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 21:23:04 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/04 21:35:21 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*copy1;
	unsigned char	*copy2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	copy1 = (unsigned char *)str1;
	copy2 = (unsigned char *)str2;
	while (copy1[i] == copy2[i] && i < n)
	{
		i++;
		if (i == n)
			return (0);
	}
	return ((int)(copy1[i] - copy2[i]));
}
