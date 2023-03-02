/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:06:30 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/02 10:23:51 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	game_init_bonus(t_game *game)
{
	set_mlx(game);
	set_tileset(game);
	set_tileset_bonus(game);
	set_data(game);
	game_display_bonus(game);
}

void	set_tileset_bonus(t_game *game)
{
	game->tileset.slime = \
		mlx_xpm_file_to_image(game->mlx.mlx_p, "imgs/slime.xpm", &s, &s);
}
