/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_requirements_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:59:01 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 16:57:29 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	are_elements_valid(char **map, t_game *game);
void	set_player_data(t_check *check, t_map *map, int x, int y);
t_bool	is_complete_bonus(t_check *check, t_nb *nb);
t_bool	is_complete(t_check *check, t_nb *nb);

t_bool	is_complete_and_valid(char **map, t_game *game)
{
	if (!are_elements_valid(map, game))
	{
		ft_printf("Error\nUnexpected element in map. ");
		return (0);
	}
	if (BONUS)
	{
		if (is_complete_bonus(&game->check, &game->nb) == FALSE)
		{
			ft_printf("Error\nSome elements are missing. ");
			return (0);
		}
	}
	else
	{
		if (is_complete(&game->check, &game->nb) == FALSE)
		{
			ft_printf("Error\nSome elements are missing. ");
			return (0);
		}
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
			else if (map[y][x] == 'S')
				game->check.slime++;
			else if (map[y][x] == 'P')
				set_player_data(&game->check, &game->map, x, y);
			else if (map[y][x] != '1' && map[y][x] != '0')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	set_player_data(t_check *check, t_map *map, int x, int y)
{
	check->cat++;
	map->cat_x = x;
	map->cat_y = y;
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
}

t_bool	is_complete(t_check *check, t_nb *nb)
{
	if (check->exit != 1)
	{
		ft_printf("Error\nExit is missing. ");
		return (0);
	}
	if (check->cat != 1)
	{
		ft_printf("Error\nPlayer is missing. ");
		return (0);
	}
	if (nb->apple < 1)
	{
		ft_printf("Error\nNo collectible. ");
		return (0);
	}
	return (1);
}
