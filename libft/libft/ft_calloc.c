/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:02:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:56:28 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The calloc() function contiguously allocates enough space for count objects that
are size bytes of memory each and returns a pointer to the allocated memory. The
allocated memory is filled with bytes of value zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (!count || !size)
	{
		ptr = malloc(0);
		return (ptr);
	}
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	while (i < count * size)
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}
