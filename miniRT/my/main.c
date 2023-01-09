/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:13 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/09 14:57:17 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int ac, char **av)
{
	t_scene	scene;

	if (ac != 2)
		exit_with_error("Wrong argument format\n");
	set_mlx(&scene.mlx);
	parse(&scene, av[1]);
}