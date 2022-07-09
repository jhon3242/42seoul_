/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:02:39 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/07/09 21:08:00 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_pos(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.size.x)
	{
		y = 0;
		while (y < game->map.size.y)
		{
			if (game->map.chunks[x][y] == 'P')
			{
				game->player.pos.x = x;
				game->player.pos.y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
