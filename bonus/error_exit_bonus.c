/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:11:54 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/30 13:31:15 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	error_exit(t_game *game, char *message)
{
	if (message)
		ft_printf("%s", message);
	endgame(game);
}

int	endgame(t_game *game)
{
	if (game->map.layout)
		ft_strs_free(game->map.layout, game->map.h);
	ft_printf("Thanks for trying so_long.\n");
	exit(0);
}
