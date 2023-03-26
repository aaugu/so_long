/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:42:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 15:28:30 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../include/game.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments.\n");
		return (0);
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game || !is_all_valid_bonus(argv[1], game))
	{
		free(game);
		return (0);
	}
	game_init(game);
	mlx_key_hook(game->mlx.win, key_hook_bonus, game);
	mlx_hook(game->mlx.win, 17, 0, endgame, game);
	mlx_loop(game->mlx.mlx_p);
	free(game);
	return (0);
}
