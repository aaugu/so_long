/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:35:32 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:47:43 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_print_int(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_print_s("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_print_c('-');
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_print_int(n / 10);
		count += ft_print_int(n % 10);
	}
	else if (n < 10)
		count += ft_print_c(n + 48);
	return (count);
}
