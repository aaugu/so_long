/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:08:09 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 18:20:07 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "./game.h"

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

/* ---------------	FILE AND MAP REQUIREMENTS CHECK	--------------- */
t_bool	is_all_valid(const char *filename, t_game *game);
char	**map_parsing(const char *filename);
t_bool	is_map_valid(char **map, t_game *game);
t_bool	is_complete_and_valid(char **map, t_game *game);

/* ---------------	GAME INIT	--------------- */
void	game_init(t_game *game);

void	error_exit(t_game *game, char *message);

#endif
