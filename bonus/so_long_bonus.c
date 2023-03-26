/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:09:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 00:29:51 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments.\n");
		return (0);
	}
	if (!is_all_valid_bonus(argv[1], &game))
		return (0);
	game_init_bonus(&game);
	mlx_key_hook(game.mlx.win, key_hook_bonus, &game);
	mlx_hook(game.mlx.win, 17, 0, endgame, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
