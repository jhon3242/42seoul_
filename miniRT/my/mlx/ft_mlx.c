/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:45:01 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/09 16:54:54 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int mlx_esc_exit(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	mlx_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	set_mlx(t_mlx *mlx)
{
	mlx->width = MLX_WIDTH;
	mlx->height = MLX_HEIGHT;
	mlx->canvas_ratio = MLX_RATIO;
	mlx->mlx = mlx_init();
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "miniRT");
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
		&mlx->line_length, &mlx->endian);
	mlx_key_hook(mlx->win, mlx_esc_exit, mlx); // ESC
	mlx_hook(mlx->win, X_EVENT_KEY_EXIT, 0, &mlx_exit, mlx); 
}