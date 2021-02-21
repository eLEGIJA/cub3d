/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:34:09 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/12 23:34:09 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if ((c >= (unsigned char)'A' && (unsigned char)'Z' >= c)\
		|| (c >= (unsigned char)'a' && (unsigned char)'z' >= c))
		return (1);
	return (0);
}
