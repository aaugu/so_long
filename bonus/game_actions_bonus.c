/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:27:50 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/29 19:49:48 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	action(t_game *game, int x, int y);
void	move_cat(t_game *game, int x, int y);
void	collect_apple(t_game *game, int x, int y);
void	victory(t_game *game);

int	key_hook(int keycode, t_game *game)
{
	if (keycode == A || keycode == LEFT)
		action(game, -1, 0);
	else if (keycode == S || keycode == DOWN)
		action(game, 0, 1);
	else if (keycode == D || keycode == RIGHT)
		action(game, 1, 0);
	else if (keycode == W || keycode == UP)
		action(game, 0, -1);
	else if (keycode == ESC)
		endgame(game);
	game_display(game);
	return (0);
}

void	action(t_game *game, int x, int y)
{
	char	nxt_tile;

	nxt_tile = game->map.layout[game->map.cat_y + y][game->map.cat_x + x];
	if (nxt_tile == '0')
		move_cat(game, x, y);
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
}

void	move_cat(t_game *game, int x, int y)
{
	if (x == -1 && y == 0)
		game->move.left = 1;
	if (x == 0 && y == 1)
		game->move.down = 1;
	if (x == 1 && y == 0)
		game->move.right = 1;
	if (x == 0 && y == -1)
		game->move.up = 1;
	game->map.cat_x += x;
	game->map.cat_y += y;
	game->nb.moves++;
}

void	collect_apple(t_game *game, int x, int y)
{
	move_cat(game, x, y);
	game->nb.apple--;
	ft_printf("You pick up an apple !\n");
	ft_printf("There are %d left to collect\n", game->nb.apple);
	if (game->nb.apple == 0)
	{
		ft_printf("You're ready to prepare a nice apple pie. ");
		ft_printf("Go put your loot in the chest to bring them safe home\n");
	}
}

void	victory(t_game *game)
{
	game->nb.moves++;
	ft_printf("Moves > %d - Congratulations! ", game->nb.moves, game->nb.apple);
	endgame(game);
}
