/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:01:51 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 15:40:20 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "./so_long.h"
# include "./so_long_bonus.h"

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

#endif
