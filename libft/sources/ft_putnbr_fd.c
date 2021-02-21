/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elegija <elegija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 22:40:28 by msafflow          #+#    #+#             */
/*   Updated: 2021/02/21 11:04:43 by elegija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(long n, int fd)
{
	long	copy;

	copy = n;
	if (fd < 0)
		return ;
	if (copy < 0)
	{
		write(fd, "-", 1);
		copy = copy * -1;
	}
	if (copy > 9)
	{
		ft_putnbr_fd(copy / 10, fd);
		ft_putnbr_fd(copy % 10, fd);
	}
	else
		ft_putchar_fd(copy + '0', fd);
}
