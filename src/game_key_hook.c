/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:10:23 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/06 16:10:44 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	game_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		action(game, -1, 0);
	if (keycode == KEY_S)
		action(game, 0, 1);
	if (keycode == KEY_D)
		action(game, 1, 0);
	if (keycode == KEY_W)
		action(game, 0, -1);
	return (0);
}

void	action(t_game *game, int x, int y)
{
	char	nxt_tile;

	nxt_tile = game->map.layout[game->map.player_y + y][game->map.player_x + x];
	if (nxt_tile == '0')
		ft_printf("Herbe");
	// 	move_player(game, x, y);
	if (nxt_tile == 'C')
	{
		ft_printf("Pomme");
		// game->map.layout[game->map.player_y + y][game->map.player_x + x] = '0';
		// game->data.apple--;
		// move_player(game, x, y);
	}
	// if (is_exit(game) && game->data.apple == 0)
	// 	victory(game);
}
