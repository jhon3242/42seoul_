/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeyhan <chaeyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:13 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/02/12 13:05:41 by chaeyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_scene	scene;

	if (ac != 2)
		exit_with_error("Wrong argument format\n");
	set_mlx(&scene.mlx);
	parse(&scene, av[1]);
	drawing(&scene);
	mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.img, 0, 0);
	mlx_loop(scene.mlx.mlx);
}
