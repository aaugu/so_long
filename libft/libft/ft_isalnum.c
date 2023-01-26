/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:02:03 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:56:33 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The isalnum() function tests for any character for which isalpha(3) or
isdigit(3) is true.  The value of the argument must be representable as an
unsigned char or the value of EOF.
Returns zero if the character tests false and returns non-zero if the character
tests true.
*/

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
