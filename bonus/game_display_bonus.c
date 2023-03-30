/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:26:38 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/30 13:32:48 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	display_base_map(t_mlx mlx, t_map map, t_tileset tileset);
void	display_exit(t_mlx mlx, t_map map, t_tileset tileset, int nb_apple);
void	display_player(t_mlx mlx, t_tileset tileset, t_map map, t_move *move);
void	display_moves(t_game *game, t_mlx mlx, int nb_moves);

void	game_display(t_game *game)
{
	display_base_map(game->mlx, game->map, game->tileset);
	display_exit(game->mlx, game->map, game->tileset, game->nb.apple);
	display_player(game->mlx, game->tileset, game->map, &game->move);
	display_moves(game, game->mlx, game->nb.moves);
}

void	display_base_map(t_mlx mlx, t_map map, t_tileset tileset)
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
			if (map.layout[y][x] == 'S')
				put_image(mlx, tileset.slime, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	display_exit(t_mlx mlx, t_map map, t_tileset tileset, int nb_apple)
{
	if (nb_apple == 0)
		put_image(mlx, tileset.exit_o, map.exit_x, map.exit_y);
	else
		put_image(mlx, tileset.exit, map.exit_x, map.exit_y);
}

void	display_player(t_mlx mlx, t_tileset tileset, t_map map, t_move *move)
{
	if (move->down == TRUE)
	{
		put_image(mlx, tileset.cat, map.cat_x, map.cat_y);
		move->down = 0;
	}
	if (move->up == TRUE)
	{
		put_image(mlx, tileset.cat_b, map.cat_x, map.cat_y);
		move->up = 0;
	}
	if (move->left == TRUE)
	{
		put_image(mlx, tileset.cat_l, map.cat_x, map.cat_y);
		move->left = 0;
	}
	if (move->right == TRUE)
	{
		put_image(mlx, tileset.cat_r, map.cat_x, map.cat_y);
		move->right = 0;
	}
}

void	display_moves(t_game *game, t_mlx mlx, int nb_moves)
{
	char	*moves;

	moves = ft_itoa(nb_moves);
	if (!moves)
		error_exit(game, "Something went wrong.");
	mlx_string_put(mlx.mlx, mlx.win, TILE_W * 0.5, TILE_H * 0.8, 0xFFFFFF, \
	"Moves : ");
	mlx_string_put(mlx.mlx, mlx.win, TILE_W * 4, TILE_H * 0.8, 0xFFFFFF, moves);
	free(moves);
}
