/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:01:11 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:57:54 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Outputs the character ’c’ to the given file descriptor.

c: The character to output.
fd: The file descriptor on which to write.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
