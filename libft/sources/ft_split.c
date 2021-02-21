/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elegija <elegija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 23:15:44 by msafflow          #+#    #+#             */
/*   Updated: 2021/02/21 11:04:18 by elegija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_w(char const *str, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			words++;
		while (str[i] != c && str[i])
			i++;
	}
	return (words);
}

size_t		ft_l(char const *str, char c)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0' && str[i] != c)
	{
		length++;
		i++;
	}
	return (length);
}

void		*ft_clean(char **arr, size_t words)
{
	size_t	i;

	i = -1;
	while (++i < words)
		free(arr[i]);
	free(arr);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	size_t	w;
	size_t	i;
	size_t	j;
	char	**arr;

	i = 0;
	w = -1;
	if (!s || !c || !(arr = (char**)malloc(sizeof(char*) * (ft_w(s, c) + 1))))
		return (NULL);
	while (++w < ft_w(s, c))
	{
		j = 0;
		if (!(arr[w] = (char*)malloc(sizeof(char) * (ft_l(&s[i], c) + 1))))
		{
			ft_clean(arr, i);
			return (NULL);
		}
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			arr[w][j++] = s[i++];
		arr[w][j] = '\0';
	}
	arr[w] = NULL;
	return (arr);
}
