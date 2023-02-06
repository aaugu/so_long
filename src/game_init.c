/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:06:30 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/06 11:16:50 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	game_init(t_game game)
{
	set_mlx(game);
	set_tileset(game);
	set_data(game);
	game_display(game);
}

void	set_mlx(t_game game)
{
	game.mlx->mlx = mlx_init();
	game.mlx.w = TILE_SIZE * game.map.w;
	game.mlx.h = TILE_SIZE * game.map.h;
	game.mlx->win = mlx_new_window(mlx, game.mlx.w, game.mlx.h, "so_long");
}

void	set_tileset(t_game game)
{
	int	img_s;

	img_s = TILE_SIZE;
	game->tileset->apple = \
		mlx_xpm_file_to_image(mlx, "images/apple.xpm", &img_s, &img_s);
	game->tileset->exit = \
		mlx_xpm_file_to_image(mlx, "images/exit_c.xpm", &img_s, &img_s);
	game->tileset->grass = \
		mlx_xpm_file_to_image(mlx, "images/grass.xpm", &img_s, &img_s);
	game->tileset->player = \
		mlx_xpm_file_to_image(mlx, "images/player_f.xpm", &img_s, &img_s);
	game->tileset->wall = \
		mlx_xpm_file_to_image(mlx, "images/wall.xpm", &img_s, &img_s);
}

void	set_data(t_game game)
{
	game.data.moves = 0;
}
