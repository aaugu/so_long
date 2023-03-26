/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:09:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 18:18:11 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/game.h"

void	error_exit(t_game *game, char *message);
int		endgame(t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments.\n");
		return (0);
	}
	if (!is_all_valid(argv[1], &game))
		return (0);
	game_init(&game);
	mlx_key_hook(game.mlx.win, key_hook, &game);
	mlx_hook(game.mlx.win, 17, 0, endgame, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}

void	error_exit(t_game *game, char *message)
{
	ft_printf("%s", message);
	endgame(game);
}

int	endgame(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->map.layout)
		ft_free_dptr(game->map.layout, game->map.h);
	ft_printf("Thanks for trying so_long.\n");
	exit(0);
}
