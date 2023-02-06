/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:18:35 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/06 13:36:02 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	is_all_valid(const char *filename, t_game *game)
{
	char	**map;

	if (!is_extension_valid(filename))
		return (0);
	map = map_parsing(filename);
	if (!map || !is_map_valid(map, game))
		return (0);
	game->map.layout = map;
	return (1);
}

t_bool	is_extension_valid(const char *filename)
{
	int		i;
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strlen(extension) > 4)
	{
		ft_printf("Error, file extension is not valid. Try again\n");
		return (0);
	}
	if (ft_strcmp(extension, ".ber") == 0)
		return (1);
	return (0);
}
