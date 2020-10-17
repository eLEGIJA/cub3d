/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:23:19 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:23:19 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*newmem;

	newmem = (void*)malloc(nmemb * size);
	if (!newmem)
		return (0);
	ft_memset(newmem, 0, nmemb * size);
	return (newmem);
}
