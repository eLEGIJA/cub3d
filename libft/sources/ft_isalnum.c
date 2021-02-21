/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:19:46 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:08:36 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= (unsigned char)'0' && c <= (unsigned char)'9') \
		|| (c >= (unsigned char)'A' && c <= (unsigned char)'Z') \
		|| (c >= (unsigned char)'a' && c <= (unsigned char)'z'))
		return (1);
	return (0);
}
