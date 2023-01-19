/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:01:11 by aaugu             #+#    #+#             */
/*   Updated: 2022/12/17 17:53:43 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the character ’c’ to the given file descriptor.

c: The character to output.
fd: The file descriptor on which to write.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
