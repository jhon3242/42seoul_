/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:16:57 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/07/09 21:08:12 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(const char *str)
{
	printf("Error : %s\n", str);
	exit(1);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	printf("Game End!");
	exit(0);
}
