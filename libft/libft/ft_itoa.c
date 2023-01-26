/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:00:32 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:56:55 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Allocates (with malloc(3)) and returns a string representing the integer
received as an argument, or NULL if allocation fails. Negative numbers must be
handled.

n: the integer to convert.
*/

int		ft_intsize(int n);
void	ft_convertint(int n, int size, char *str);

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_intsize(n);
	if (n < 0)
		size++;
	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	ft_convertint(n, size, str);
	return (str);
}

int	ft_intsize(int n)
{
	int	size;

	size = 1;
	n /= 10;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

void	ft_convertint(int n, int size, char *str)
{
	while (n > 0 && size > 0)
	{
		str[size-- - 1] = n % 10 + '0';
		n /= 10;
	}
}
