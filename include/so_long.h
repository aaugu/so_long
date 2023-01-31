/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:13:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/31 14:30:11 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"

/* ---------------	TYPEDEF	--------------- */

typedef int	t_bool;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**layout;
}				t_window;

typedef struct s_map
{
	int		width;
	int		height;
	char	**layout;
}				t_map;

typedef struct s_tileset
{
	void	*apple;
	void	*player;
	void	*slime;
	void	*exit;
	void	*grass;
	void	*wall;
}				t_tileset;

typedef struct s_data
{
	int		nb_player;
	int		nb_apples;
	int		nb_exit;
}				t_data;

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

/* ---------------	TILES SIZE	--------------- */
# define TILE_SIZE	16

/* ---------------	KEYCODES	--------------- */
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

/* ---------------	FILE CHECKS	--------------- */
t_bool	is_extension_valid(const char *filename);

/* ---------------	MAP PARSING	--------------- */
char	**map_parsing(char *filename);
int		count_lines(char *filename);
char	**ft_freeall(char **strs);

/* ---------------	MAP CHECKS	--------------- */
t_bool	is_map_valid(char **map);
t_bool	is_rectangular(char **map);
t_bool	is_closed(char **map);
t_bool	is_solvable(char **map);
t_bool	has_all_elements(char **map);

#endif
