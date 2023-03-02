/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:16:36 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/02 09:48:07 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	game_display_bonus(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.h)
	{
		while (x < game->map.w)
		{
			put_image(game, game->tileset.grass, x, y);
			if (game->map.layout[y][x] == '1')
				put_image(game, game->tileset.wall, x, y);
			if (game->map.layout[y][x] == 'C')
				put_image(game, game->tileset.apple, x, y);
			if (game->map.layout[y][x] == 'E')
				put_image(game, game->tileset.exit, x, y);
			if (game->map.layout[y][x] == 'P')
				put_image(game, game->tileset.cat, x, y);
			if (game->map.layout[y][x] == 'S')
				put_image(game, game->tileset.slime, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	put_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx.mlx_p, game->mlx.win, image, \
		x * TILE_W, y * TILE_H);
}
