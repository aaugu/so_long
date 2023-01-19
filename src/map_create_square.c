/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:36:29 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/19 14:12:52 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	create_square(int x, int y, void *mlx_ptr, void *win_ptr)
{
	while (y <= 16)
	{
		while (x <= 16)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xc1d470);
			x++;
		}
		if (y > 16)
			break ;
		x = 0;
		y++;
	}
}