/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:18:35 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 11:45:17 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	is_extension_valid(const char *filename)
{
	int		i;
	char	*extension;

	extension = ft_strchr(filename, '.');
	if (!extension)
		return (0);
	if (ft_strcmp(extension, ".ber") == 0)
		return (1);
	return (0);
}
