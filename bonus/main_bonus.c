/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:51:44 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/29 19:52:19 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

t_bool	is_extension_valid(const char *filename);
void	map_data_init(t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;
	int i = 0;

	if (argc != 2)
		error_exit(&game, "Error\nWrong number of arguments.\n");
	if (is_extension_valid(argv[1]) == FALSE)
		return (0);
	game.map.layout = map_parsing(argv[1]);
	if (!game.map.layout)
		return (0);
	map_data_init(&game);
	if (is_map_valid(game.map.layout, &game) == FALSE)
		error_exit(&game, "Try again with a valid map.\n");
	while (i < game.map.h)
		ft_printf("%s\n", game.map.layout[i++]);
	// game_init(&game);
	// game_display(game);
	// mlx_key_hook(game.mlx.win, key_hook, &game);
	// mlx_hook(game.mlx.win, 17, 0, endgame, &game);
	// mlx_loop(game.mlx.mlx);
	return (0);
}

t_bool	is_extension_valid(const char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strlen(extension) > 4)
	{
		ft_printf("Error\nFile extension is not valid. Try again\n");
		return (0);
	}
	if (ft_strcmp(extension, ".ber") == 0)
		return (1);
	return (0);
}

void	map_data_init(t_game *game)
{
	game->nb.apple = 0;
	game->check.apple = 0;
	game->check.exit = 0;
	game->check.cat = 0;
	game->check.slime = 0;
}

void put_image(t_mlx mlx, void *image, int x, int y)
{
	mlx_put_image_to_window(mlx.mlx, mlx.win, image, x * TILE_W, y * TILE_H);
}
