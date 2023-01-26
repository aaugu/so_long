/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:03:25 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:58:46 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The strnstr() function locates the first occurrence of the null-terminated
string needle in the string haystack, where not more than len characters are
searched. Characters that appear after a `\0' character are not searched. Since
the strnstr() function is a FreeBSD specific API, it should only be used when
portability is not a concern.
If needle is an empty string, haystack is returned; if needle occurs nowhere in
haystack, NULL is returned; otherwise a pointer to the first character of the
first occurrence of needle is returned.
*/

int	is_matching(const char *str, const char *to_find, size_t i, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;

	i = 0;
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (0);
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			if (is_matching(haystack, needle, i, len))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

int	is_matching(const char *str, const char *to_find, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (to_find[j] && to_find[j] == str[i + j] && i + j < len)
		j++;
	if (to_find[j] == '\0')
		return (1);
	else
		return (0);
}
