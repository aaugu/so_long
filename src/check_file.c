/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:18:35 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/24 14:21:24 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	is_all_valid(const char *filename, t_game *game)
{
	char	**map;

	if (!is_extension_valid(filename))
		return (0);
	map = map_parsing(filename);
	map_data_init(game);
	if (!map || !is_map_valid(map, game))
	{
		ft_freeall(map);
		return (0);
	}
	game->map.layout = map;
	return (1);
}

t_bool	is_extension_valid(const char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strlen(extension) > 4)
	{
		ft_printf("Error\nFile extension is not valid. Try again\n");
		return (0);
	}
	if (ft_strcmp(extension, ".ber") == 0)
		return (1);
	return (0);
}

void	map_data_init(t_game *game)
{
	game->nb.apple = 0;
	game->check.exit = 0;
	game->check.cat = 0;
}
