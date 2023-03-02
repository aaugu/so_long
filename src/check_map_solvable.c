/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_solvable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:51:49 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/02 11:18:30 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	is_solvable(char **map, t_game *game)
{
	game->check.map = ft_copy_dptr((const char**)map, game->map.h);
	if (!game->check.map)
		return (0);
	game->check.apple = game->nb.apple;
	fill_path(game->check.map, game->map.cat_x, game->map.cat_y, game);
	ft_free_dptr(game->check.map, game->map.h);
	if (!has_all_elements(game))
		return (0);
	return (1);
}

void	fill_path(char **map, int x, int y, t_game *game)
{
	if (map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'P' || \
		map[y][x] == '0')
	{
		if (map[y][x] == 'C')
			game->check.apple--;
		if (map[y][x] == 'E')
			game->check.exit--;
		if (map[y][x] == 'P')
			game->check.cat--;
		map[y][x] = 'O';
		fill_path(map, x + 1, y, game);
		fill_path(map, x, y + 1, game);	
		fill_path(map, x, y - 1, game);
		fill_path(map, x - 1, y, game);
	}
	return ;
}

t_bool	has_all_elements(t_game *game)
{
	if (game->check.exit != 0)
	{
		ft_printf("Error\nExit can't be reached. ");
		return (0);
	}
	if (game->check.apple != 0)
	{
		ft_printf("Error\nAll apples can't be reached. ");
		return (0);
	}
	return (1);
}
