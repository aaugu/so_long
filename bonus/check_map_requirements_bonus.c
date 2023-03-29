/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_requirements_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:26:52 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/29 19:55:08 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

t_bool	is_rect(char **map, t_game *game);
t_bool	is_closed(char **map, t_game *game);
t_bool	is_closed_horizontal(char *map);

t_bool	is_map_valid(char **map, t_game *game)
{
	if (!is_rect(map, game))
	{
		ft_printf("Error\nMap is not rectangular. ");
		return (0);
	}
	if (!is_closed(map, game))
	{
		ft_printf("Error\nMap not closed by wall. ");
		return (0);
	}
	if (!is_solvable(map, game))
	{
		ft_printf("Error\nMap not solvable. ");
		return (0);
	}
	if (!is_complete_and_expected(map, game))
		return (0);
	return (1);
}
t_bool	is_rect(char **map, t_game *game)
{
	int	x;
	int	y;
	int	save_x;

	y = 0;
	save_x = ft_strlen(map[y]);
	while (map[y])
	{
		x = ft_strlen(map[y]);
		if (save_x != x)
			return (0);
		y++;
	}
	if (x == y)
		return (0);
	game->map.w = x;
	game->map.h = y;
	return (1);
}

t_bool	is_closed(char **map, t_game *game)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (y == 0 || map[y + 1] == NULL)
		{
			if (!is_closed_horizontal(map[y]))
				return (0);
		}
		else if (map[y][0] != '1' || map[y][game->map.w - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

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
