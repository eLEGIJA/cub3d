/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:26:46 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:26:46 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strrchr(const char *str, int c)
{
	const char *sym;
	const char *tmp = NULL;

	if (!c)
		return ((char *)str + ft_strlen(str));
	sym = ft_strchr(str, c);
	while (sym)
	{
		tmp = sym;
		sym = ft_strchr(sym + 1, c);
	}
	return ((char *)tmp);
}
