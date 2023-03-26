/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:08:09 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 00:39:20 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "./game.h"

typedef struct s_map
{
	int		w;
	int		h;
	int		cat_x;
	int		cat_y;
	int		exit_x;
	int		exit_y;
	char	**layout;
}				t_map;

typedef struct s_tileset
{
	void	*apple;
	void	*cat;
	void	*cat_b;
	void	*cat_l;
	void	*cat_r;
	void	*exit;
	void	*exit_o;
	void	*grass;
	void	*slime;
	void	*wall;
}				t_tileset;
typedef struct s_check
{
	int		apple;
	int		cat;
	int		exit;
	int		slime;
	char	**map;
}				t_check;

/* ---------------	FILE AND MAP REQUIREMENT CHECKS	--------------- */
t_bool	is_all_valid_bonus(const char *filename, t_game *game);
t_bool	is_map_valid_bonus(char **map, t_game *game);
t_bool	is_complete_and_valid_bonus(char **map, t_game *game);

/* ---------------	MAP SOLVABLE CHECK	--------------- */
t_bool	is_solvable_bonus(char **map, t_game *game);

/* ---------------	GAME INIT	--------------- */
void	game_init_bonus(t_game *game);

/* ---------------	GAME DISPLAY	--------------- */
void	game_display_bonus(t_mlx mlx, t_map map, t_tileset tileset);

/* ---------------	GAME ACTIONS	--------------- */
int		key_hook_bonus(int keycode, t_game *game);

#endif
