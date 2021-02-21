/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:28:33 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/20 16:26:52 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*copy1;
	unsigned char	*copy2;

	copy1 = (unsigned char *)str1;
	copy2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	i = 0;
	while ((copy1[i] != '\0') && (copy2[i] != '\0') && i < (n - 1))
	{
		if (copy1[i] != copy2[i])
			break ;
		i++;
	}
	return (copy1[i] - copy2[i]);
}
