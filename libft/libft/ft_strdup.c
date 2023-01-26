/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:02:29 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:58:16 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The strdup() function allocates sufficient memory for a copy of the string s1,
does the copy, and returns a pointer to it. The pointer may subsequently be used
as an argument to the function free(3). If insufficient memory is available,
NULL is returned and errno is set to ENOMEM. The strndup() function copies at
most n characters from the string s1 always NUL terminating the copied string.
*/

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
