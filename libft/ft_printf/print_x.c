/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:36:04 by aaugu             #+#    #+#             */
/*   Updated: 2022/12/16 15:36:04 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_print_x(char c, long unsigned int n)
{
	int					count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_x(c, n / 16);
		count += ft_print_x(c, n % 16);
	}
	else
	{
		if (n <= 9)
			count += ft_print_c(n + 48);
		else
		{
			if (c == 'x')
				count += ft_print_c(n - 10 + 'a');
			else if (c == 'X')
				count += ft_print_c(n - 10 + 'A');
		}
	}
	return (count);
}
