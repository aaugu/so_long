/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:27:50 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/02 10:19:30 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_cat_bonus(t_game *game, int x, int y)
{
	game->map.layout[game->map.cat_y][game->map.cat_x] = '0';
	game->map.layout[game->map.cat_y + y][game->map.cat_x + x] = 'P';
	game->map.cat_x += x;
	game->map.cat_y += y;
	game->nb.moves++;
	change_cat_dir(game, x, y);
	game_display(game);
	ft_printf("Moves > %d\n", game->nb.moves);
}

void	collect_apple_bonus(t_game *game, int x, int y)
{
	move_cat_bonus(game, x, y);
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
	free_dptr(game->map.layout);
	ft_printf("Thanks for playing so_long !\n");
	exit(0);
}

void	change_cat_dir(t_game *game, int x, int y)
{
	if (x == 0 && y == 1)
		put_image(game, game->tileset.cat_d, x, y);
	if (x == 0 && y == -1)
		put_image(game, game->tileset.cat_u, x, y);
	if (x == 1 && y == 0)
		put_image(game, game->tileset.cat_r, x, y);
	if (x == -1 && y == 0)
		put_image(game, game->tileset.cat_l, x, y);
}