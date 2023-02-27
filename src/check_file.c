/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:18:35 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/27 14:08:04 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	is_all_valid(const char *filename, t_game *game)
{
	if (!is_extension_valid(filename))
		return (0);
	map_data_init(game);
	game->map.layout = map_parsing(filename);
	ft_printf("game->map.layout > %p\n", game->map.layout);
	if (!game->map.layout || !is_map_valid(game->map.layout, game))
		return (0);
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
	game->check.apple = 0;
	game->check.exit = 0;
	game->check.cat = 0;
}
