/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:03:31 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:59:02 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The toupper() function converts a lower-case letter to the corresponding upper-
case letter. The argument must be representable as an unsigned char or the value
of EOF. If the argument is a lower-case letter, returns the corresponding upper-
case letter if there is one; otherwise, the argument is returned unchanged.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
