/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:06:30 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 19:23:30 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	set_mlx_bonus(t_mlx *mlx, t_map map);
void	set_tileset_bonus(t_tileset *tileset, void *mlx);

void	game_init_bonus(t_game *game)
{
	set_mlx(&game->mlx, game->map);
	set_tileset(&game->tileset, game->mlx.mlx);
	set_data(&game->nb);
	game_display_bonus(game->mlx, game->map, game->tileset);
}

void	set_mlx_bonus(t_mlx *mlx, t_map map)
{
	set_mlx(mlx, map);
	mlx->h = TILE_H * (map.h + 1);
}

void	set_tileset_bonus(t_tileset *tileset, void *mlx)
{
	int	s;

	set_tileset(tileset, mlx);
	tileset->slime = mlx_xpm_file_to_image(mlx, "imgs/slime.xpm", &s, &s);
}
