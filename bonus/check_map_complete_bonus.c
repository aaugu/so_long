/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_complete_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:27:03 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 10:24:26 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

t_bool	are_elements_valid_bonus(char **map, t_game *game);
t_bool	is_complete_bonus(t_check *check, t_nb *nb);

t_bool	is_complete_and_valid_bonus(char **map, t_game *game)
{
	if (are_elements_valid_bonus(map, game) == FALSE)
	{
		ft_printf("Error\nUnexpected element in map. ");
		return (0);
	}
	if (is_complete_bonus(&game->check, &game->nb) == FALSE)
		return (0);
	return (1);
}

t_bool	are_elements_valid_bonus(char **map, t_game *game)
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
				set_player_data(&game->check, &game->map, x, y);
			if (map[y][x] == 'S')
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

t_bool	is_complete_bonus(t_check *check, t_nb *nb)
{
	if (is_complete(check, nb) == FALSE)
		return (0);
	if (check->slime < 1)
	{
		ft_printf("Error\nNo enemy. ");
		return (0);
	}
	return (1);
}
