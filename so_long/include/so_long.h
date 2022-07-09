/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:06:26 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/07/09 21:10:21 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../lib/libmlx/mlx.h"
# include "../lib/libgnl/include/get_next_line.h"
# include "../lib/libft/include/libft.h"

# define MLX_KEY_PRESS 2
# define MLX_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0

# define PX 64

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_flag
{
	int	player;
	int	exit;
	int	item;
}				t_flag;

typedef struct s_player
{
	int		move_count;
	int		item_count;
	t_pos	pos;
}				t_player;

typedef struct s_map
{
	t_pos	size;
	char	**chunks;
	t_flag	flags;
}				t_map;

typedef struct s_img
{
	void	*road;
	void	*wall;
	void	*item;
	void	*player;
	void	*exit;
}				t_img;

typedef struct s_game
{
	t_map		map;
	t_img		imgs;
	t_player	player;
	void		*mlx;
	void		*window;
}				t_game;

/* so_long_check.c
## =====================================================
*/
void	check_map_path(const char *path, const char *suffix);
void	check_shape(t_map *map);
void	check_surround(t_map *map);
void	check_component(t_map *map);

/* so_long_init_game.c
## =====================================================
*/
void	init_game(t_game *game, char *map_path);
void	init_map(t_game *game, char *map_path);
void	init_player(t_game *game);
void	init_mlx_window(t_game *game);
void	init_img(t_game *game);

/* so_long_map.c
## =====================================================
*/
void	get_map_size(t_map *map);
void	get_map_chunks(t_game *game, const char *path);

/* so_long_close.c
## =====================================================
*/
void	print_error(const char *str);
int		close_game(t_game *game);

/* so_long_player.c
## =====================================================
*/
void	set_player_pos(t_game *game);

/* so_long_img.c
## =====================================================
*/
void	*get_img(t_game *game, char *path);
void	put_img(t_game *game, void *img, t_pos pos);

/* so_long_draw.c
## =====================================================
*/
void	drawing(t_game *game);

/* so_long_press.c
## =====================================================
*/
int		key_press(int keycode, t_game *game);

/* so_long_move.c
## =====================================================
*/
void	move(t_game *game, const int dxdy[2]);

#endif