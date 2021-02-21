/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:37:15 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:09:41 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			copy = ft_lstlast(*(lst));
			copy->next = new;
		}
	}
}
