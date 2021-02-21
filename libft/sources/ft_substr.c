/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:39:25 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/09 23:45:33 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;

	if (!str)
		return (NULL);
	if (ft_strlen(str) < start)
		return (ft_strdup(""));
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(sub, str + start, len + 1);
	return (sub);
}
