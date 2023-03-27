/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:26:38 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 10:57:26 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	game_display_bonus(t_mlx mlx, t_map map, t_tileset tileset)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map.h)
	{
		while (x < map.w)
		{
			put_image(mlx, tileset.grass, x, y);
			if (map.layout[y][x] == '1')
				put_image(mlx, tileset.wall, x, y);
			if (map.layout[y][x] == 'C')
				put_image(mlx, tileset.apple, x, y);
			if (map.layout[y][x] == 'E')
				put_image(mlx, tileset.exit, x, y);
			if (map.layout[y][x] == 'P')
				put_image(mlx, tileset.cat, x, y);
			if (map.layout[y][x] == 'S')
				put_image(mlx, tileset.slime, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_string_put(mlx.mlx, mlx.win, TILE_W, mlx.h, 0, "Moves : ");
}
