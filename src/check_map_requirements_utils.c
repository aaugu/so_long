/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_requirements_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:59:01 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/28 15:57:02 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	is_closed_horizontal(char *map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		if (map[x] != '1')
			return (0);
		x++;
	}
	return (1);
}

t_bool	are_elements_valid(char **map, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				game->nb.apple++;
			else if (map[y][x] == 'E')
				game->check.exit++;
			else if (map[y][x] == 'P')
				set_player_data(game, x, y);
			else if (map[y][x] != '1' && map[y][x] != '0')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	set_player_data(t_game *game, int x, int y)
{
	game->check.cat++;
	game->map.cat_x = x;
	game->map.cat_y = y;
}
