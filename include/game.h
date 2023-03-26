/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:01:51 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 00:39:04 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "./so_long.h"

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

/* ---------------	FILE AND MAP REQUIREMENT CHECKS	--------------- */
t_bool	is_extension_valid(const char *filename);
void	map_data_init(t_game *game);
char	**map_parsing(const char *filename);

t_bool	is_rect(char **map, t_game *game);
t_bool	is_closed(char **map, t_game *game);
t_bool	is_closed_horizontal(char *map);

void	set_player_data(t_check *check, t_map *map, int x, int y);
t_bool	is_complete(t_check *check, t_nb *nb);

/* ---------------	MAP SOLVABLE CHECK	--------------- */
t_bool	all_elements_reacheable(t_check *check);

/* ---------------	GAME INIT	--------------- */
void	set_mlx(t_mlx *mlx, t_map map);
void	set_tileset(t_tileset *tileset, void *mlx);
void	set_data(t_nb *nb);

/* ---------------	GAME DISPLAY	--------------- */
void	put_image(t_mlx mlx, void *image, int x, int y);

/* ---------------	GAME ACTIONS	--------------- */
void	collect_apple(t_game *game, int x, int y);
void	victory(t_game *game);

/* ---------------	ERRORS AND ENDGAME	--------------- */
void	error_exit(t_game *game, char *message);
int		endgame(t_game *game);

#endif
