/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:06:30 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 18:12:59 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_mlx(t_mlx *mlx, t_map map);
void	set_tileset(t_tileset *tileset, void *mlx);
void	set_data(t_nb *nb);

void	game_init(t_game *game)
{
	set_mlx(&game->mlx, game->map);
	set_tileset(&game->tileset, game->mlx.mlx);
	set_data(&game->nb);
	game_display(game->mlx, game->map, game->tileset);
}

void	set_mlx(t_mlx *mlx, t_map map)
{
	mlx->mlx = mlx_init();
	mlx->w = TILE_W * map.w;
	if (BONUS)
		mlx->h = TILE_H * (map.h + 1);
	else
		mlx->h = TILE_H * map.h;
	mlx->win = mlx_new_window(mlx->mlx, mlx->w, mlx->h, "so_long");
}

void	set_tileset(t_tileset *tileset, void *mlx)
{
	int	s;

	tileset->apple = mlx_xpm_file_to_image(mlx, "imgs/apple.xpm", &s, &s);
	tileset->cat = mlx_xpm_file_to_image(mlx, "imgs/cat.xpm", &s, &s);
	tileset->exit = mlx_xpm_file_to_image(mlx, "imgs/exit_c.xpm", &s, &s);
	tileset->grass = mlx_xpm_file_to_image(mlx, "imgs/grass.xpm", &s, &s);
	tileset->slime = mlx_xpm_file_to_image(mlx, "imgs/slime.xpm", &s, &s);
	tileset->wall = mlx_xpm_file_to_image(mlx, "imgs/wall.xpm", &s, &s);
}

void	set_data(t_nb *nb)
{
	nb->moves = 0;
}
