/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:03:27 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:59:06 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The tolower() function converts an upper-case letter to the corresponding lower-
case letter. The argument must be representable as an unsigned char or the value
of EOF. If the argument is an upper-case letter, returns the corresponding lower
-case letter if there is one; otherwise, the argument is returned unchanged.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
