/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:36:09 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/24 10:27:28 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == A || keycode == LEFT)
		action(game, -1, 0);
	if (keycode == S || keycode == DOWN)
		action(game, 0, 1);
	if (keycode == D || keycode == RIGHT)
		action(game, 1, 0);
	if (keycode == W || keycode == UP)
		action(game, 0, -1);
	if (keycode == ESC)
		endgame(game);
	return (0);
}

void	action(t_game *game, int x, int y)
{
	char	nxt_tile;

	nxt_tile = game->map.layout[game->map.cat_y + y][game->map.cat_x + x];
	if (nxt_tile == '0')
		move_cat(game, x, y);
	if (nxt_tile == 'C')
		collect_apple(game, x, y);
	if (nxt_tile == 'E' && game->nb.apple != 0)
		ft_printf("There are still %d apples to collect !\n", game->nb.apple);
	if (nxt_tile == 'E' && game->nb.apple == 0)
		victory(game, x, y);
}
