/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:02:12 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:56:47 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The isdigit() function tests for a decimal digit character. Regardless of
locale, this includes the following characters only: 0,1,2,3,4,5,6,7,8,9. The
value of the argument must be representable as an unsigned char or the value of
EOF.
Returns zero if the character tests false and return non-zero if the character
tests true.
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
