/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:27:50 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/22 13:57:02 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_cat(t_game *game, int x, int y)
{
	game->map.layout[game->map.cat_y][game->map.cat_x] = '0';
	game->map.layout[game->map.cat_y + y][game->map.cat_x + x] = 'P';
	game->map.cat_x += x;
	game->map.cat_y += y;
	game->data.moves++;
	game_display(game);
	ft_printf("%d pas\n", game->data.moves);
}

void	collect_apple(t_game *game, int x, int y)
{
	game->map.layout[game->map.cat_y + y][game->map.cat_x + x] = '0';
	game->data.apple--;
	move_cat(game, x, y);
	ft_printf("Vous avez ramassé une pomme !\n");
	ft_printf("Il en reste %d à récupérer\n", game->data.apple);
	if (game->data.apple == 0)
		ft_printf("Vous pouvez maintenant les ranger !\n");
}

void	victory(t_game *game, int x, int y)
{
	game->data.moves++;
	game->map.layout[game->map.cat_y][game->map.cat_x] = '0';
	game_display(game);
	put_image(game, game->tileset.cat, game->map.cat_x + x, \
		game->map.cat_y + y);
	ft_printf("%d pas - Bravo!\n", game->data.moves, game->data.apple);
	endgame(game);
}

void	endgame(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx_p, game->mlx.win);
	ft_printf("Merci d'avoir joué à so_long !\n");
	exit(0);
}
