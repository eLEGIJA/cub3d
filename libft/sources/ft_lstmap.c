/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:40:50 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:26:05 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*copy;
	t_list	*begin;

	if (lst)
	{
		copy = lst;
		if (!(begin = ft_lstnew(f(copy->content))))
			return (NULL);
		copy = copy->next;
		while (copy)
		{
			if (!(new = ft_lstnew(f(copy->content))))
			{
				ft_lstclear(&begin, del);
				return (NULL);
			}
			ft_lstadd_back(&begin, new);
			copy = copy->next;
		}
		return (begin);
	}
	return (NULL);
}
