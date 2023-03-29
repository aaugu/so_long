/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_complete_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:27:03 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/29 19:54:07 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

t_bool	are_elements_expected(char **map, t_game *game);
t_bool	is_complete(t_check *check, t_nb *nb);
void 	set_player_data(t_game *game, int x, int y);
void	set_exit_data(t_check *check, t_map *map, int x, int y);

t_bool	is_complete_and_expected(char **map, t_game *game)
{
	if (are_elements_expected(map, game) == FALSE)
	{
		ft_printf("Error\nUnexpected element in map. ");
		return (0);
	}
	if (is_complete(&game->check, &game->nb) == FALSE)
		return (0);
	return (1);
}

t_bool	are_elements_expected(char **map, t_game *game)
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
				set_exit_data(&game->check, &game->map, x, y);
			else if (map[y][x] == 'P')
				set_player_data(game, x, y);
			else if (map[y][x] == 'S')
				game->check.slime++;
			else if (map[y][x] != '1' && map[y][x] != '0')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

t_bool	is_complete(t_check *check, t_nb *nb)
{
	if (check->exit != 1)
		ft_printf("Error\nExit is missing. ");
	if (check->cat != 1)
		ft_printf("Error\nPlayer is missing. ");
	if (nb->apple < 1)
		ft_printf("Error\nNo collectible. ");
	if (check->slime < 1)
		ft_printf("Error\nNo enemy. ");
	if (check->exit != 1 || check->cat != 1 || nb->apple < 1 || \
		check->slime < 1)
		return (0);
	return (1);
}

void	set_player_data(t_game *game, int x, int y)
{
	game->check.cat++;
	game->map.cat_x = x;
	game->map.cat_y = y;
	game->map.layout[y][x] = '0';
}

void	set_exit_data(t_check *check, t_map *map, int x, int y)
{
	check->exit++;
	map->exit_x = x;
	map->exit_y = y;
}
