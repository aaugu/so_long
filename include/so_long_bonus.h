/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:08:09 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/30 13:20:01 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;
}				t_mlx;

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

typedef struct s_nb
{
	int		apple;
	int		moves;
}				t_nb;

typedef struct s_check
{
	int		apple;
	int		cat;
	int		exit;
	int		slime;
	char	**map;
}				t_check;

typedef struct s_move
{
	t_bool		left;
	t_bool		right;
	t_bool		up;
	t_bool		down;
}				t_move;

typedef struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_tileset	tileset;
	t_nb		nb;
	t_check		check;
	t_move		move;
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

/* ---------------	FILE AND MAP PARSING	--------------- */
char	**map_parsing(const char *filename);

/* ---------------	MAP CHECKS	--------------- */
t_bool	is_map_valid(char **map, t_game *game);
t_bool	is_complete_and_expected(char **map, t_game *game);
t_bool	is_solvable(char **map, t_game *game);

/* ---------------	GAME INIT	--------------- */
void	game_init(t_game *game);
void	set_data(t_nb *nb);

/* ---------------	GAME DISPLAY	--------------- */
void	game_display(t_game *game);
void	put_image(t_mlx mlx, void *image, int x, int y);

/* ---------------	GAME ACTIONS	--------------- */
void	action(t_game *game, int x, int y);

/* ---------------	ERRORS AND EXIT	--------------- */
void	error_exit(t_game *game, char *message);
int		endgame(t_game *game);

#endif
