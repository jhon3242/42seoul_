/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:11:59 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/07/14 12:42:08 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		print_error("Input Error.");
	init_game(&game, av[1]);
	drawing(&game);
	mlx_hook(game.window, MLX_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.window, MLX_KEY_EXIT, 0, &close_game, &game);
	mlx_loop(game.mlx);
}
