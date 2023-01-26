/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:19:56 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:58:13 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The strchr() function locates the first occurrence of c (converted to a char) in
the string pointed to by s.  The terminating null character is considered to be
part of the string; therefore if c is `\0', the function locate the terminating
`\0'.
Returns a pointer to the located character, or NULL if the character does
not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	return (NULL);
}
