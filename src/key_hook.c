/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:36:09 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/22 13:37:06 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
		action(game, -1, 0);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		action(game, 0, 1);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		action(game, 1, 0);
	if (keycode == KEY_W || keycode == KEY_UP)
		action(game, 0, -1);
	if (keycode == KEY_ESC)
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
	if (nxt_tile == 'E' && game->data.apple != 0)
		ft_printf("Il reste encore %d pommes à ramasser !\n", game->data.apple);
	if (nxt_tile == 'E' && game->data.apple == 0)
		victory(game, x, y);
}
