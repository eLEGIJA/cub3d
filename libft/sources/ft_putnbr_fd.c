/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:25:40 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:25:40 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr_fd(long n, int fd)
{
	char			symb;
	unsigned long	m;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	m = (unsigned long)n;
	if (m >= 10)
	{
		ft_putnbr_fd(m / 10, fd);
		symb = (m % 10) + '0';
		write(fd, &symb, 1);
	}
	if (m >= 0 && m <= 9)
	{
		symb = m + '0';
		write(fd, &symb, 1);
	}
}
