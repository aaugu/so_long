/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:09:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/31 14:01:05 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int	deal_key(int key, void *param)
// {
// 	ft_putnbr_fd(key, 1);
// 	ft_putchar_fd('\n', 1);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	char	**map;
	int		y = 0;
	int		x = 0;
	int		img_w = 16;
	int		img_h = 16;
	void	*mlx = mlx_init();;
	void	*win = mlx_new_window(mlx, TILE_SIZE * 13, TILE_SIZE * 5, "so_long");
	void	*grass = mlx_xpm_file_to_image(mlx, "images/grass1.xpm", &img_w, &img_h);
	void	*wall = mlx_xpm_file_to_image(mlx, "images/wall.xpm", &img_w, &img_h);
	void	*player = mlx_xpm_file_to_image(mlx, "images/player_front.xpm", &img_w, &img_h);
	void	*collec = mlx_xpm_file_to_image(mlx, "images/collectible.xpm", &img_w, &img_h);
	void	*exit_c = mlx_xpm_file_to_image(mlx, "images/exit_c.xpm", &img_w, &img_h);

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments\n");
		return (0);
	}
	if (!is_extension_valid(argv[1]))
		return (0);
	map = map_parsing(argv[1]);
	if (!map)
		return (0);
	while (y < 5)
	{
		while (x < 13)
		{
			mlx_put_image_to_window(mlx, win, grass, x * TILE_SIZE, y * TILE_SIZE);
			ft_printf("%c", map[y][x]);
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, wall, x * TILE_SIZE, y * TILE_SIZE);
			if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, collec, x * TILE_SIZE, y * TILE_SIZE);
			if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, exit_c, x * TILE_SIZE, y * TILE_SIZE);
			if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, player, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		ft_printf("\n");
		x = 0;
		y++;
	}
	mlx_loop(mlx);
	return (0);
}
/*
	void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "so_long");

	img = mlx_xpm_file_to_image(mlx, "images/grass1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_loop(mlx);
*/

/*
key int
A : 0
S : 1
D : 2
W : 13
esc : 53
*/
