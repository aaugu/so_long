/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:05:48 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 14:59:15 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

t_bool	is_all_valid_bonus(const char *filename, t_game *game)
{
	if (!is_extension_valid(filename))
		return (0);
	map_data_init_bonus(game);
	game->map.layout = map_parsing(filename);
	if (!game->map.layout)
		return (0);
	if (!is_map_valid(game->map.layout, game))
	{
		free_dptr(game->map.layout);
		ft_printf("Try again with a valid map.\n");
		return (0);
	}
	return (1);
}

void	map_data_init_bonus(t_game *game)
{
	game->nb.apple = 0;
	game->check.apple = 0;
	game->check.exit = 0;
	game->check.cat = 0;
	game->check.slime = 0;
}
