/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:38:38 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/07/05 22:24:16 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_component(t_game *game, t_pos pos)
{
	
	put_img(game, game->imgs.road, pos);
	if (game->map.chunks[pos.x][pos.y] == '1')
		put_img(game, game->imgs.wall, pos);
	else if (game->map.chunks[pos.x][pos.y] == 'P')
		put_img(game, game->imgs.player, pos);
	else if (game->map.chunks[pos.x][pos.y] == 'C')
		put_img(game, game->imgs.item, pos);
	else if (game->map.chunks[pos.x][pos.y] == 'E')
		put_img(game, game->imgs.exit, pos);
}

void	drawing(t_game *game)
{
	t_pos	pos;

	pos.x = 0;
	while (pos.x < game->map.size.x)
	{
		pos.y = 0;
		while (pos.y < game->map.size.y)
		{
			put_component(game, pos);
			pos.y++;
		}
		pos.x++;
	}
}