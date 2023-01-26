/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:34:56 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:47:50 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_parse_input(const char *input, va_list args);
int	ft_parse_flags(char c, va_list args);

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	if (!input)
		return (0);
	va_start(args, input);
	count = ft_parse_input(input, args);
	va_end(args);
	return (count);
}

int	ft_parse_input(const char *input, va_list args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			count += ft_parse_flags(input[i + 1], args);
			i++;
		}
		else
			count += ft_print_c(input[i]);
		i++;
	}
	return (count);
}

int	ft_parse_flags(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_c(va_arg(args, int));
	else if (c == 's')
		count = ft_print_s(va_arg(args, char *));
	else if (c == 'p')
		count = ft_print_p((long unsigned int)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count = ft_print_int(va_arg(args, int));
	else if (c == 'u')
		count = ft_print_uns_int((long unsigned int)va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_print_x(c, (long unsigned int)va_arg(args, unsigned int));
	else if (c == '%')
		count = ft_print_c('%');
	return (count);
}
