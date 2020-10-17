/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:25:36 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:25:36 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putnbr_base_fd(long n, int fd, size_t base, int cap)
{
	char			symb;
	unsigned long	m;
	char			cp;

	cp = cap ? 'A' : 'a';
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	m = (unsigned long)n;
	if (m >= base)
	{
		ft_putnbr_base_fd(m / base, fd, base, cap);
		symb = (m % base) + (m % base > 9 ? cp - 10 : '0');
		write(fd, &symb, 1);
	}
	if (m >= 0 && m <= base - 1)
	{
		symb = m + (m % base > 9 ? cp - 10 : '0');
		write(fd, &symb, 1);
	}
}
