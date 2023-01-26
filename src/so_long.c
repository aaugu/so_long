/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:09:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 16:31:59 by aaugu            ###   ########.fr       */
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

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments\n");
		return (0);
	}
	if (!is_file_valid(argv[1]))
		return (0);
	*map = map_parsing(argv[1]);
	if (!is_map_valid(*map))
		return (0);
	return (0);
}
/*
	void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "so_long");
	map_init(mlx, win);

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
