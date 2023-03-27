/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_requirements_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:26:52 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 11:03:53 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

t_bool	is_map_valid_bonus(char **map, t_game *game)
{
	if (!is_rect(map, game))
	{
		ft_printf("Error\nMap is not rectangular. ");
		return (0);
	}
	if (!is_closed(map, game))
	{
		ft_printf("Error\nMap not closed by wall. ");
		return (0);
	}
	if (!is_complete_and_valid_bonus(map, game))
		return (0);
	if (!is_solvable_bonus(map, game))
	{
		ft_printf("Error\nMap not solvable. ");
		return (0);
	}
	return (1);
}
