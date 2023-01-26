/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:12:57 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:58:00 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Outputs the integer ’n’ to the given file descriptor.

n: The integer to output.
fd: The file descriptor on which to write.
*/

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else if (nb >= 0 && nb < 10)
		ft_putchar_fd(nb + 48, fd);
}
