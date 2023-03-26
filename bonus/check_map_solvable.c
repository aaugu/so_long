/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_solvable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:51:49 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 17:15:03 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_path(char **map, int x, int y, t_check *check);
t_bool	all_elements_reacheable(t_check *check);

t_bool	is_solvable(char **map, t_game *game)
{
	game->check.map = ft_copy_dptr((const char **)map, game->map.h);
	if (!game->check.map)
		return (0);
	game->check.apple = game->nb.apple;
	fill_path(game->check.map, game->map.cat_x, game->map.cat_y, &game->check);
	ft_free_dptr(game->check.map, game->map.h);
	if (all_elements_reacheable(&game->check) == FALSE)
		return (0);
	return (1);
}

void	fill_path(char **map, int x, int y, t_check *check)
{
	if (map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'P' || \
		map[y][x] == '0')
	{
		if (map[y][x] == 'C')
			check->apple--;
		if (map[y][x] == 'E')
			check->exit--;
		if (map[y][x] == 'P')
			check->cat--;
		if (map[y][x] == 'S')
			check->slime--;
		map[y][x] = 'O';
		fill_path(map, x + 1, y, check);
		fill_path(map, x, y + 1, check);
		fill_path(map, x, y - 1, check);
		fill_path(map, x - 1, y, check);
	}
	return ;
}

t_bool	all_elements_reacheable(t_check *check)
{
	if (check->exit != 0)
	{
		ft_printf("Error\nExit can't be reached. ");
		return (0);
	}
	if (check->apple != 0)
	{
		ft_printf("Error\nAll apples can't be reached. ");
		return (0);
	}
	if (BONUS)
	{
		if (check->slime != 0)
		{
			ft_printf("Error\nEnemy can't be encountered. ");
			return (0);
		}
	}
	return (1);
}
