/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:11:54 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/28 15:14:43 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	error_exit_bonus(char *message)
{
	if (message)
		ft_printf("%s", message);
	endgame_bonus();
}

int	endgame_bonus(void)
{
	ft_printf("Thanks for trying so_long.\n");
	exit(0);
}
