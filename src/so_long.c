/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:09:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/19 15:34:40 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	deal_key(int key, void *param)
{
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*img_path = "../images/grass1.xpm";
	int		img_width = 16;
	int		img_height = 16;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 16 * 24, 16 * 20, "so_long");

	img = mlx_new_image(mlx, img_width, img_height);
	img = mlx_xpm_file_to_image(mlx, img_path, &img_width, &img_height);
	
	// mlx_put_image_to_window (mlx, window, img, 0, 0);

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
