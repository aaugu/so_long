/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:27:50 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/02 11:21:10 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_cat(t_game *game, int x, int y)
{
	game->map.layout[game->map.cat_y][game->map.cat_x] = '0';
	game->map.layout[game->map.cat_y + y][game->map.cat_x + x] = 'P';
	game->map.cat_x += x;
	game->map.cat_y += y;
	game->nb.moves++;
	game_display(game);
	ft_printf("Moves > %d\n", game->nb.moves);
}

void	collect_apple(t_game *game, int x, int y)
{
	move_cat(game, x, y);
	game->nb.apple--;
	ft_printf("You pick up an apple !\n");
	ft_printf("There are %d left to collect\n", game->nb.apple);
	if (game->nb.apple == 0)
		ft_printf("Now, you're free to go !\n");
}

void	victory(t_game *game)
{
	game->nb.moves++;
	ft_printf("Moves > %d - Congratulations!\n", game->nb.moves, game->nb.apple);
	endgame(game);
}

int	endgame(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx_p, game->mlx.win);
	ft_free_dptr(game->map.layout, game->map.h);
	ft_printf("Thanks for playing so_long !\n");
	exit(0);
}
