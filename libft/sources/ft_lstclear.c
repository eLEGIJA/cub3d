/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:02 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/14 16:24:02 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*it;
	t_list	*tmp;

	if (!lst)
		return ;
	it = *lst;
	while (it)
	{
		tmp = it;
		it = it->next;
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
}
