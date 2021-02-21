/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 21:35:19 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:11:49 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_lstsize(t_list *lst)
{
	unsigned int	size;
	t_list			*copy;

	if (lst == NULL)
		return (0);
	copy = lst;
	size = 0;
	while (copy)
	{
		copy = copy->next;
		size++;
	}
	return (size);
}
