/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:15:15 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 16:59:49 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_length(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	length;
	long	n_copy;

	length = ft_length(n);
	n_copy = (long)n;
	if (n < 0)
	{
		n_copy = (long)n * -1;
		length++;
	}
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, length + 1);
	str[--length] = n_copy % 10 + '0';
	while (n_copy /= 10)
		str[--length] = n_copy % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
