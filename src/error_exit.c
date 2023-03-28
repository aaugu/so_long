/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:27:35 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/28 14:29:29 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(t_game *game, char *message)
{
	if (message)
		ft_printf("%s", message);
	endgame(game);
}

int	endgame(t_game *game)
{
	int	i;
	
	ft_printf("%p\n", game->map.layout);
	// ft_printf("%s", game->map.layout[0]);
	i = 0;
	while (i < game->map.h)
	{
		ft_printf("%c", game->map.layout[0][i]);
		i++;
	}
	ft_printf("\n-------\n");
	if (game->map.layout)
		ft_strs_free(game->map.layout, game->map.h);
	ft_printf("Thanks for trying so_long.\n");
	exit(0);
}
