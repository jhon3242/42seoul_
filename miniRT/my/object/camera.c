/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:44:12 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/09 16:52:56 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	camera(t_scene *scene, char **data)
{
	t_camera	camera;
	double		degree;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;

	camera.orig = parse_vec3(data[1]);
	camera.camera_dir = vunit(parse_vec3(data[2]));
	degree = ft_atod(data[3]);
}