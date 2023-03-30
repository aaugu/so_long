/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:27:50 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/30 13:19:01 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_cat(t_game *game, int x, int y);
void	change_direction(t_move *move, int x, int y);
void	collect_apple(t_game *game, int x, int y);
void	victory(t_game *game);

void	action(t_game *game, int x, int y)
{
	char	nxt_tile;

	nxt_tile = game->map.layout[game->map.cat_y + y][game->map.cat_x + x];
	if (nxt_tile == '0')
		move_cat(game, x, y);
	else if (nxt_tile == 'C')
		collect_apple(game, x, y);
	else if (nxt_tile == 'E' && game->nb.apple != 0)
	{
		ft_printf("There are still %d apples to collect !\n", game->nb.apple);
		change_direction(&game->move, x, y);
	}
	else if (nxt_tile == 'E' && game->nb.apple == 0)
		victory(game);
	else if (nxt_tile == 'S')
	{
		ft_printf("You've been defeated by a slime and lost all your apples! ");
		endgame(game);
	}
	else
		change_direction(&game->move, x, y);
}

void	move_cat(t_game *game, int x, int y)
{
	change_direction(&game->move, x, y);
	game->map.cat_x += x;
	game->map.cat_y += y;
	game->nb.moves++;
}

void	change_direction(t_move *move, int x, int y)
{
	if (x == -1 && y == 0)
		move->left = 1;
	if (x == 0 && y == 1)
		move->down = 1;
	if (x == 1 && y == 0)
		move->right = 1;
	if (x == 0 && y == -1)
		move->up = 1;
}

void	collect_apple(t_game *game, int x, int y)
{
	move_cat(game, x, y);
	game->map.layout[game->map.cat_y][game->map.cat_x] = '0';
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
