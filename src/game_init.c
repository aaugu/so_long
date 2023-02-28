/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:06:30 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/28 14:38:06 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_init(t_game *game)
{
	set_mlx(game);
	set_tileset(game);
	set_data(game);
	game_display(game);
}

void	set_mlx(t_game *game)
{
	game->mlx.mlx_p = mlx_init();
	game->mlx.w = TILE_W * game->map.w;
	game->mlx.h = TILE_H * game->map.h;
	game->mlx.win = \
		mlx_new_window(game->mlx.mlx_p, game->mlx.w, game->mlx.h, "so_long");
}

void	set_tileset(t_game *game)
{
	int	s;

	game->tileset.apple = \
		mlx_xpm_file_to_image(game->mlx.mlx_p, "imgs/apple.xpm", &s, &s);
	game->tileset.exit = \
		mlx_xpm_file_to_image(game->mlx.mlx_p, "imgs/exit_c.xpm", &s, &s);
	game->tileset.grass = \
		mlx_xpm_file_to_image(game->mlx.mlx_p, "imgs/grass.xpm", &s, &s);
	game->tileset.cat = \
		mlx_xpm_file_to_image(game->mlx.mlx_p, "imgs/cat.xpm", &s, &s);
	game->tileset.wall = \
		mlx_xpm_file_to_image(game->mlx.mlx_p, "imgs/wall.xpm", &s, &s);
}

void	set_data(t_game *game)
{
	game->nb.moves = 0;
}
