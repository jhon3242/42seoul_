/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:06:07 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/07/05 17:44:07 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_img(t_game *game, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img)
		print_error("Failed to get image");
	return (img);
}

void	put_img(t_game *game, void *img, t_pos pos)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	mlx_put_image_to_window(game->mlx, game->window, img, x * PX, y * PX);
}