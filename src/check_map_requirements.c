/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_requirements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:49:14 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/27 11:56:40 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	is_map_valid(char **map, t_game *game)
{
	if (!map)
		return (0);
	if (!is_rect(map, game) || !is_closed(map) || \
		!is_complete(map, game, 0, 0) || !is_solvable(map, game))
	{
		ft_printf("Try again with a valid map.\n");
		return (0);
	}
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
		{
			ft_printf("Error\nMap is not rectangular. ");
			return (0);
		}
		y++;
	}
	if (x == y)
	{
		ft_printf("Error\nMap is square. ");
		return (0);
	}
	game->map.w = x;
	game->map.h = y;
	return (1);
}

t_bool	is_closed(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (y == 0 || map[y + 1] == 0)
		{
			if (!is_closed_horizontal(map[y]))
				return (0);
		}
		else if (map[y][0] != '1' || map[y][ft_strlen(map[y]) - 1] != '1')
		{
			ft_printf("Error\nMap not closed by wall. ");
			return (0);
		}
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
		{
			ft_printf("Error\nMap not closed by wall. ");
			return (0);
		}
		x++;
	}
	return (1);
}

t_bool	is_complete(char **map, t_game *game, int x, int y)
{
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				game->nb.apple++;
			if (map[y][x] == 'E')
				game->check.exit++;
			if (map[y][x] == 'P')
			{
				game->check.cat++;
				game->map.cat_x = x;
				game->map.cat_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (game->check.exit == 1 && game->check.cat == 1 \
		&& game->nb.apple >= 1)
		return (1);
	ft_printf("Error\nMap doesn't have expected elements. ");
	return (0);
}
