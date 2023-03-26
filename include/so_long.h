/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:13:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 00:39:51 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "./game.h"

typedef struct s_map
{
	int		w;
	int		h;
	int		cat_x;
	int		cat_y;
	char	**layout;
}				t_map;
typedef struct s_tileset
{
	void	*apple;
	void	*cat;
	void	*exit;
	void	*grass;
	void	*wall;
}				t_tileset;
typedef struct s_check
{
	int		apple;
	int		cat;
	int		exit;
	char	**map;
}				t_check;

/* ---------------	FILE AND MAP REQUIREMENTS CHECK	--------------- */
t_bool	is_all_valid(const char *filename, t_game *game);
t_bool	is_map_valid(char **map, t_game *game);
t_bool	is_complete_and_valid(char **map, t_game *game);

/* ---------------	MAP SOLVABLE CHECK	--------------- */
t_bool	is_solvable(char **map, t_game *game);

/* ---------------	GAME INIT	--------------- */
void	game_init(t_game *game);

/* ---------------	GAME DISPLAY	--------------- */
void	game_display(t_mlx mlx, t_map map, t_tileset tileset);

/* ---------------	HOOKS	--------------- */
int		key_hook(int keycode, t_game *game);
#endif
