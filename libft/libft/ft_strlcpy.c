/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:03:16 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:58:31 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The strlcpy() function copy strings with the same input parameters and output
result as snprintf(3). It is designed to be safer, more consistent, and less
error prone replacements for the easily misused function strncpy(3).
Strlcpy() take the full size of the destination buffer and guarantee
NUL-termination if there is room. Note that room for the NUL should be included
in dstsize.
Strlcpy() copies up to dstsize - 1 characters from the string src to dst,
NUL-terminating the result if dstsize is not 0.
If the src and dst strings overlap, the behavior is undefined.
The strlcpy() function returns the total length of the string they tried to
create, that means the length of src.
If the return value is >= dstsize, the output string has been truncated. It is
the caller's responsibility to handle this.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (!dst || !src || !dstsize)
		return (len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
