/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:36:09 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/03 11:14:21 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

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
	if (nxt_tile == '1')
		change_cat_dir(game, x, y);
	if (nxt_tile == '0')
		move_cat_bonus(game, x, y);
	if (nxt_tile == 'C')
		collect_apple_bonus(game, x, y);
	if (nxt_tile == 'S')
	{
		ft_printf("You fell on a slime and lost all your apples. Try again!");
		endgame(game);
	}
	if (nxt_tile == 'E' && game->nb.apple != 0)
	{
		change_cat_dir(game, x, y);
		ft_printf("There are still %d apples to collect !\n", game->nb.apple);
	}
	if (nxt_tile == 'E' && game->nb.apple == 0)
		victory(game);
}
