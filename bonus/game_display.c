/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:16:36 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 17:36:26 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_image(t_mlx mlx, void *image, int x, int y);

void	game_display(t_mlx mlx, t_map map, t_tileset tileset)
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
}

void	put_image(t_mlx mlx, void *image, int x, int y)
{
	mlx_put_image_to_window(mlx.mlx, mlx.win, image, x * TILE_W, y * TILE_H);
}
