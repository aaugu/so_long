/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:13:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/26 15:37:29 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "./game.h"

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
