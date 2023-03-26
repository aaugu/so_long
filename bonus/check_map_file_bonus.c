/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:26:57 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 19:26:59 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	map_data_init_bonus(t_game *game);

t_bool	is_all_valid_bonus(const char *filename, t_game *game)
{
	if (is_extension_valid(filename) == FALSE)
		return (0);
	map_data_init_bonus(game);
	game->map.layout = map_parsing(filename);
	if (!game->map.layout)
		return (0);
	if (is_map_valid(game->map.layout, game) == FALSE)
		error_exit(game, "Try again with a valid map.\n");
	return (1);
}

void	map_data_init_bonus(t_game *game)
{
	map_data_init(game);
	game->check.slime = 0;
}
