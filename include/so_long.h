/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:13:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/02 11:10:58 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"

/* ---------------	TYPEDEF	--------------- */

typedef int	t_bool;

typedef struct s_mlx
{
	void	*mlx_p;
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
	char	**layout;
}				t_map;

typedef struct s_tileset
{
	void	*apple;
	void	*exit;
	void	*grass;
	void	*cat;
	void	*wall;
}				t_tileset;

typedef struct s_nb
{
	int		moves;
	int		apple;
}				t_nb;

typedef struct s_check
{
	int		apple;
	int		exit;
	int		cat;
	char	**map;
}				t_check;

typedef struct t_game
{
	t_mlx		mlx;
	t_map		map;
	t_tileset	tileset;
	t_nb		nb;
	t_check		check;
}				t_game;

/* ---------------	TILES SIZE	--------------- */
# define TILE_W	16
# define TILE_H	16

# define TRUE 1

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

/* ---------------	FILE CHECKS	--------------- */
t_bool	is_all_valid(const char *filename, t_game *game);
t_bool	is_extension_valid(const char *filename);
void	map_data_init(t_game *game);

/* ---------------	MAP PARSING	--------------- */
char	**map_parsing(const char *filename);
int		count_lines(const char *filename);
char	**fill_map(const char *filename, int line_nb);

/* ---------------	MAP REQUIREMENTS CHECK	--------------- */
t_bool	is_map_valid(char **map, t_game *game);
t_bool	is_rect(char **map, t_game *game);
t_bool	is_closed(char **map, t_game *game);
t_bool	is_closed_horizontal(char *map);
t_bool	is_complete(char **map, t_game *game);
t_bool	are_elements_valid(char **map, t_game *game);
void	set_player_data(t_game *game, int x, int y);

/* ---------------	MAP SOLVABLE CHECK	--------------- */
t_bool	is_solvable(char **map, t_game *game);
void	fill_path(char **map, int x, int y, t_game *game);
t_bool	has_all_elements(t_game *game);

/* ---------------	GAME INIT	--------------- */
void	game_init(t_game *game);
void	set_mlx(t_game *game);
void	set_tileset(t_game *game);
void	set_data(t_game *game);

/* ---------------	GAME DISPLAY	--------------- */
void	game_display(t_game *game);
void	put_image(t_game *game, void *image, int x, int y);

/* ---------------	HOOKS	--------------- */
int		key_hook(int keycode, t_game *game);

/* ---------------	GAME ACTIONS	--------------- */
void	action(t_game *game, int x, int y);
void	move_cat(t_game *game, int x, int y);
void	collect_apple(t_game *game, int x, int y);
void	victory(t_game *game);
int		endgame(t_game *game);

#endif
