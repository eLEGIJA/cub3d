/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:34:29 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:05:11 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	size_t				i;
	unsigned long long	num;
	int					minus;

	minus = 1;
	i = 0;
	num = 0;
	while (str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\r' || str[i] == '\v' ||
		str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num < 9223372036854775807)
			num = num * 10 + (str[i++] - '0');
		if (num > 9223372036854775807 && minus < 0)
			return (0);
		else if (num > 9223372036854775807)
			return (-1);
	}
	return ((int)num * minus);
}
