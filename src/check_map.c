/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:49:14 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/27 10:40:02 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	is_map_valid(const char **map)
{
	if (!is_rectangular(*map) || !is_closed(*map) || !has_all_elements(*map) \
	|| !is_solvable(*map))
	{
		ft_printf("Error, map is not valid\n");
		return (0);
	}
	return (1);
}
