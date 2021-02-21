/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 21:06:23 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:03:26 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;
	size_t	length;

	i = -1;
	if (str == NULL || f == NULL)
		return (NULL);
	length = ft_strlen(str);
	if (!(new = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	while (str[++i])
		new[i] = f(i, str[i]);
	new[i] = '\0';
	return (new);
}
