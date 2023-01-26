/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:18:35 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 16:19:16 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	is_file_valid(const char *filename)
{
	if (is_readable(filename) && is_extension_valid(filename))
		return (1);
	ft_printf("Error\nFile is not valid\n");
	return (0);
}

t_bool	is_readable(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, map file is not readable\n");
		return (0);
	}
	close(fd);
	return (1);
}

t_bool	is_extension_valid(const char *filename)
{
	int		i;
	char	*extension;

	extension = ft_strchr(filename, '.');
	if (!extension || ft_strlen(filename) < 5)
	{
		ft_printf("Error, file extension is not valid\n");
		return (0);
	}
	if (ft_strcmp(extension, ".ber") == 0)
		return (1);
	return (0);
}
