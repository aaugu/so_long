/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:02:33 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:58:27 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The strlcat() function concatenate strings with the same input parameters and
output result as snprintf(3). It is designed to be safer, more consistent, and
less error prone replacements for the easily misused function strncat(3).
Strlcat() take the full size of the destination buffer and guarantee
NUL-termination if there is room. Note that room for the NUL should be included
in dstsize.
The strlcat() function appends string src to the end of dst. It will append at
most dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless
dstsize is 0 or the original dst string was longer than dstsize (in practice
this should not happen as it means that either dstsize is incorrect or that dst
is not a proper string).
If the src and dst strings overlap, the behavior is undefined.
The strlcat() function returns the total length of the string they tried to
create. For strlcat() that means the initial length of dst plus the length of
src. If the return value is >= dstsize, the output string has been truncated. It
is the caller's responsibility to handle this.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
