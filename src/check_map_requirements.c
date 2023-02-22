/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_requirements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:49:14 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/22 11:52:47 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	is_map_valid(char **map, t_game *game)
{
	if (!is_rect(map, game) || !is_closed(map) || !is_complete(map, game, 0, 0))
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
			ft_printf("Error, map is not rectangular.\n");
			return (0);
		}
		y++;
	}
	if (x == y)
	{
		ft_printf("Error, map is not rectangular.\n");
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
			ft_printf("Error, map not closed by wall\n");
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
			ft_printf("Error, map not closed by wall\n");
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
				game->data.apple++;
			if (map[y][x] == 'E')
				game->data.exit++;
			if (map[y][x] == 'P')
			{
				game->data.cat++;
				game->map.cat_x = x;
				game->map.cat_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (game->data.exit == 1 && game->data.cat == 1 && game->data.apple >= 1)
		return (1);
	ft_printf("Error, map doesn't have all expected elements.\n");
	return (0);
}
