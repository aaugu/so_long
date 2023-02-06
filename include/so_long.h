/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:13:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/06 14:04:48 by aaugu            ###   ########.fr       */
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
	int		player_x;
	int		player_y;
	char	**layout;
}				t_map;

typedef struct s_tileset
{
	void	*apple;
	void	*exit;
	void	*grass;
	void	*player;
	void	*wall;
}				t_tileset;

typedef struct s_data
{
	int		moves;
	int		nb_apples;
	int		nb_exit;
	int		nb_player;
}				t_data;

typedef struct t_game
{
	t_mlx		mlx;
	t_map		map;
	t_tileset	tileset;
	t_data		data;
}				t_game;

/* ---------------	TILES SIZE	--------------- */
# define TILE_SIZE	16

/* ---------------	KEYCODES	--------------- */
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

/* ---------------	FILE CHECKS	--------------- */
t_bool	is_all_valid(const char *filename, t_game *game);
t_bool	is_extension_valid(const char *filename);

/* ---------------	MAP PARSING	--------------- */
char	**map_parsing(const char *filename);
int		count_lines(const char *filename);
char	**ft_freeall(char **strs);

/* ---------------	MAP REQUIREMENTS CHECK	--------------- */
t_bool	is_map_valid(char **map, t_game *game);
t_bool	is_rect(char **map, t_game *game);
t_bool	is_closed(char **map);
t_bool	is_closed_horizontal(char *map);
t_bool	is_complete(char **map, t_game *game);

/* ---------------	MAP SOLVABLE CHECK	--------------- */
t_bool	is_solvable(char **map);

/* ---------------	GAME INIT	--------------- */
void	game_init(t_game *game);
void	set_mlx(t_game *game);
void	set_tileset(t_game *game);
void	set_data(t_game *game);

/* ---------------	GAME DISPLAY	--------------- */
void	game_display(t_game *game);
void	put_image(t_game *game, void *image, int x, int y);

#endif
