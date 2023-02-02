/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:08:09 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/02 10:09:27 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"

/* ---------------	TYPEDEF	--------------- */
typedef struct s_player
{
	void	*player_back;
	void	*player_front;
	void	*player_left;
	void	*player_right;
}				t_player;

typedef struct s_slime
{
	void	*slime_down;
	void	*slime_up;
}				t_slime;

typedef struct s_door {
	void	*door_close;
	void	*door_open;
}				t_door;

#endif