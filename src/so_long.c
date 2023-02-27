/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:09:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/27 10:39:10 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments.\n");
		return (0);
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game || !is_all_valid(argv[1], game))
	{
		free(game);
		return (0);
	}
	// game_init(game);
	// mlx_key_hook(game->mlx.win, key_hook, game);
	// // mlx_mouse_hook(game->mlx.win, mouse_hook, game);
	// mlx_loop(game->mlx.mlx_p);
	free(game);
	return (0);
}
