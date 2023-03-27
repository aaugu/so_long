/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:13:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 10:16:45 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"

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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;
}				t_mlx;

typedef struct s_nb
{
	int		apple;
	int		moves;
}				t_nb;

typedef struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_tileset	tileset;
	t_nb		nb;
	t_check		check;
}				t_game;

/* ---------------	TILES SIZE	--------------- */
# define TILE_W 16
# define TILE_H 16

/* ---------------	KEYCODES	--------------- */
# define A 0
# define S 1
# define D 2
# define W 13
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define UP 126
# define ESC 53

/* ---------------	FILE AND MAP REQUIREMENTS CHECK	--------------- */
t_bool	is_all_valid(const char *filename, t_game *game);
char	**map_parsing(const char *filename);
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

/* ---------------	ERRORS AND EXIT	--------------- */
void	error_exit(t_game *game, char *message);
int		endgame(t_game *game);

#endif
