/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:14:14 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/07/09 21:06:26 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	const int	dxdy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move(game, dxdy[0]);
	else if (keycode == KEY_S)
		move(game, dxdy[1]);
	else if (keycode == KEY_A)
		move(game, dxdy[2]);
	else if (keycode == KEY_D)
		move(game, dxdy[3]);
	return (0);
}
