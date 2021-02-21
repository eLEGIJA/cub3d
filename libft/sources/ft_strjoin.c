/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:16:06 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:02:30 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *str1, char const *str2)
{
	char	*new;
	int		len1;
	int		len2;

	if (!(str1) && !(str2))
		return (NULL);
	else if (!(str1) || !(str2))
		return (!(str2) ? ft_strdup(str1) : ft_strdup(str2));
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (!(new = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	ft_strlcpy(new, str1, len1 + 1);
	ft_strlcat(new + (len1), str2, len2 + 1);
	return (new);
}
