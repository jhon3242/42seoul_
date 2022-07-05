/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:29:48 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/07/05 17:37:01 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, char *map_path)
{
	init_map(game, map_path);
	init_player(game);
	init_mlx_window(game);
	init_img(game);
}

void	init_map(t_game *game, char *map_path)
{
	check_map_path(map_path, ".ber");
	get_map_chunks(game, map_path);
	get_map_size(&game->map);
	check_shape(&game->map);
	check_surround(&game->map);
	check_component(&game->map);
}

void	init_player(t_game *game)
{
	game->player.item_count = 0;
	game->player.move_count = 0;
	set_player_pos(game);
}

void	init_mlx_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error("Failed init mlx");
	game->window = mlx_new_window(game->mlx, game->map.size.x * PX,
			game->map.size.y * PX, "so_long");
	if (!game->window)
		print_error("Failed init window");
}

void	init_img(t_game *game)
{
	game->imgs.player = get_img(game, "./asset/player/Fox_Down.xpm");
	game->imgs.wall = get_img(game, "./asset/wall.xpm");
	game->imgs.item = get_img(game, "./asset/item.xpm");
	game->imgs.exit = get_img(game, "./asset/exit.xpm");
	game->imgs.road = get_img(game, "./asset/road.xpm");
}