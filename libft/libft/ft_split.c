/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:42:03 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:58:09 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Allocates (with malloc(3)) and returns an array of strings obtained by splitting
’s’ using the character ’c’ as a delimiter. The array must end with a NULL
pointer. Returns NULL if the allocation fails.

s: The string to be split.
c: The delimiter character.
*/

size_t	ft_countwords(char const *s, char c);
char	**ft_freeall(char **list);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	save;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_countwords(s, c) && s[j])
	{
		while (s[j] == c)
			j++;
		save = j;
		while (s[j] != c && s[j])
			j++;
		strs[i] = ft_substr(s, save, j - save);
		if (strs[i++] == 0)
			return (ft_freeall(strs));
	}
	strs[i] = NULL;
	return (strs);
}

size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != '\0' && s[i + 1] != c) || \
			(i == 0 && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_freeall(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}
