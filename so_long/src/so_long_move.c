/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:20:29 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/07/14 13:10:52 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_to_item(t_game *game, t_pos tmp)
{
	game->player.item_count++;
	game->player.move_count++;
	put_img(game, game->imgs.road, game->player.pos);
	put_img(game, game->imgs.road, tmp);
	put_img(game, game->imgs.player, tmp);
	game->map.chunks[tmp.x][tmp.y] = 'P';
	game->map.chunks[game->player.pos.x][game->player.pos.y] = '0';
	game->player.pos = tmp;
	printf("movement count : %d\n", game->player.move_count);
}

static void	move_to_road(t_game *game, t_pos tmp)
{
	game->player.move_count++;
	put_img(game, game->imgs.road, game->player.pos);
	put_img(game, game->imgs.player, tmp);
	game->map.chunks[game->player.pos.x][game->player.pos.y] = '0';
	game->player.pos = tmp;
	printf("movement count : %d\n", game->player.move_count);
}

static void	move_to_exit(t_game *game)
{
	if (game->player.item_count == game->map.flags.item)
		close_game(game);
}

void	move(t_game *game, const int dxdy[2])
{
	t_pos	tmp;

	tmp.x = game->player.pos.x + dxdy[0];
	tmp.y = game->player.pos.y + dxdy[1];
	if (game->map.chunks[tmp.x][tmp.y] == '1')
		return ;
	else if (game->map.chunks[tmp.x][tmp.y] == 'C')
		return (move_to_item(game, tmp));
	else if (game->map.chunks[tmp.x][tmp.y] == '0')
		return (move_to_road(game, tmp));
	else if (game->map.chunks[tmp.x][tmp.y] == 'E')
		return (move_to_exit(game));
}
