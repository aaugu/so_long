/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:02:22 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:57:40 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The memcmp() function compares byte string s1 against byte string s2. Both
strings are assumed to be n bytes long. Returns zero if the two strings are
identical, otherwise returns the difference between the first two differing
bytes (treated as unsigned char values, so that `\200' is greater than `\0', for
example). Zero-length strings are always identical. This behavior is not
required by C and portable code should only depend on the sign of the returned
value.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}
