/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:41:02 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:47:46 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//int	ft_print_ptr(unsigned long int n);

int	ft_print_p(unsigned long int n)
{
	int	count;

	count = ft_print_s("0x");
	count += ft_print_x('x', n);
	return (count);
}
