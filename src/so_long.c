/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:09:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 11:18:03 by aaugu            ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "images/grass1.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_loop(mlx);
	return (0);
}

/*
key int
A : 0
S : 1
D : 2
W : 13
esc : 53
*/
