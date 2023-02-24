/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_solvable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:51:49 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/24 14:25:23 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	is_solvable(char **map, t_game *game)
{
	copy_char_dptr(game->map.layout, game->check.map);
	game->check.apple = game->nb.apple;
	fill_path(game->check.map, game->map.cat_x, game->map.cat_y);
	if (game->map.exit != 0 || game->map.apple != 0)
	{
		if (game->map.exit != 0)
			ft_printf("Error\nExit can't be reached");
		if (game->map.apple != 0)
			ft_printf("Error\nAll apples can't be reached");
		ft_freeall(game->check.map);
		return (0);
	}
	ft_freeall(game->check.map);
	return (1);
}

void	copy_dptr_char(char **src, char **copy)
{
}

void	fill_path(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '0')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'P')
	{
		if (map[y][x] == 'C')
			game->check.apple--;
		if (map[y][x] == 'E')
			game->check.exit--;
		if (map[y][x] == 'P')
			game->check.cat--;
		map[y][x] = '0';
		fill_path(map, x, y--);
		fill_path(map, x, y++);
		fill_path(map, x++, y);
		fill_path(map, x--, y);
	}
	return ;
}
