/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_solvable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:51:49 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/27 15:16:21 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	is_solvable(char **map, t_game *game)
{
	copy_map(map, game);
	if (!game->check.map)
		return (0);
	game->check.apple = game->nb.apple;
	fill_path(game->check.map, game->map.cat_x, game->map.cat_y, game);
	if (game->check.exit != 0 || game->check.apple != 0)
	{
		ft_printf("Error\n");
		if (game->check.exit != 0)
			ft_printf("Exit can't be reached. ");
		if (game->check.apple != 0)
			ft_printf("All apples can't be reached. ");
		ft_freeall(game->check.map);
		return (0);
	}
	ft_freeall(game->check.map);
	return (1);
}

void	copy_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	game->check.map = (char **)malloc(sizeof(char *) * (game->map.h + 1));
	if (!game->check.map)
		return ;
	game->check.map[game->map.h] = NULL;
	while (map[i])
	{
		game->check.map[i] = ft_strdup(map[i]);
		if (!game->check.map[i++])
		{
			ft_freeall(game->check.map);
			return ;
		}
	}
}

void	fill_path(char **map, int x, int y, t_game *game)
{
	if (map[y][x] == '1')
		return ;
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
