/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:27:50 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 10:25:08 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	action_bonus(t_game *game, int x, int y);
void	move_cat_bonus(t_game *game, int x, int y);
void	new_display(t_game *game);
void	change_cat_dir(t_mlx mlx, t_tileset tileset, int x, int y);

int	key_hook_bonus(int keycode, t_game *game)
{
	if (keycode == A || keycode == LEFT)
		action_bonus(game, -1, 0);
	if (keycode == S || keycode == DOWN)
		action_bonus(game, 0, 1);
	if (keycode == D || keycode == RIGHT)
		action_bonus(game, 1, 0);
	if (keycode == W || keycode == UP)
		action_bonus(game, 0, -1);
	if (keycode == ESC)
		endgame(game);
	return (0);
}

void	action_bonus(t_game *game, int x, int y)
{
	char	nxt_tile;

	nxt_tile = game->map.layout[game->map.cat_y + y][game->map.cat_x + x];
	if (nxt_tile == '0')
		move_cat_bonus(game, x, y);
	else if (nxt_tile == 'C')
		collect_apple(game, x, y);
	else if (nxt_tile == 'E' && game->nb.apple != 0)
		ft_printf("There are still %d apples to collect !\n", game->nb.apple);
	else if (nxt_tile == 'E' && game->nb.apple == 0)
		victory(game);
	else if (nxt_tile == 'S')
	{
		ft_printf("You've been defeated by a slime and lost all your apples! ");
		endgame(game);
	}
	new_display(game);
}

void	move_cat_bonus(t_game *game, int x, int y)
{
	game->map.layout[game->map.cat_y][game->map.cat_x] = '0';
	game->map.layout[game->map.cat_y + y][game->map.cat_x + x] = 'P';
	game->map.cat_x += x;
	game->map.cat_y += y;
	game->nb.moves++;
}

void	new_display(t_game *game)
{
	char	*moves;

	game_display_bonus(game->mlx, game->map, game->tileset);
	moves = ft_itoa(game->nb.moves);
	if (!moves)
		return (error_exit(game, "Error\nSomething went wrong."));
	mlx_string_put(game->mlx.mlx, game->mlx.win, TILE_W * 5, game->mlx.h, 0, \
	moves);
	change_cat_dir(game->mlx, game->tileset, game->map.cat_x, game->map.cat_y);
	if (game->nb.apple == 0)
		put_image(game->mlx, game->tileset.exit_o, game->map.exit_x, \
		game->map.exit_y);
	free(moves);
}

void	change_cat_dir(t_mlx mlx, t_tileset tileset, int x, int y)
{
	if (x == -1 && y == 0)
		put_image(mlx, tileset.cat_l, x, y);
	if (x == 0 && y == 1)
		put_image(mlx, tileset.cat, x, y);
	if (x == 1 && y == 0)
		put_image(mlx, tileset.cat_r, x, y);
	if (x == 0 && y == -1)
		put_image(mlx, tileset.cat_b, x, y);
}
