/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:09:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/28 14:16:02 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;
	// int	i;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments.\n");
		return (0);
	}
	game.map.layout = NULL;
	if (!is_all_valid_bonus(argv[1], &game))
		return (0);
	// i = 0;
	// while (i < game.map.h)
	// {
	// 	ft_printf("%s\n", game.map.layout[i]);
	// 	i++;
	// }
	game_init_bonus(&game);
	mlx_key_hook(game.mlx.win, key_hook_bonus, &game);
	mlx_hook(game.mlx.win, 17, 0, endgame, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
