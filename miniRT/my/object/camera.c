/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeyhan <chaeyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:44:12 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/02/12 15:48:15 by chaeyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static t_point3	get_left_top(t_camera *camera, t_vec3 w)
{
	t_point3	left_top;

	left_top = vminus(vminus(vminus(camera->origin, \
				vdivide_k(camera->horizontal, 2)), \
				vdivide_k(camera->vertical, 2)), w);
	return (left_top);
}

void	camera(t_scene *scene, char **data)
{
	t_camera	camera;
	double		degree;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;

	camera.origin = parse_vec3(data[1]);
	camera.camera_dir = vunit(parse_vec3(data[2]));
	degree = ft_atod(data[3]);
	w = vunit(vmult_k(camera.camera_dir, -1));
	u = vunit(vcross(vec3(EPSILON, 1, 0), w));
	v = vmult_k(vcross(w, u), -1);
	camera.viewport_h = 2.0 * tan(degree / 360 * M_PI);
	camera.viewport_w = camera.viewport_h * MLX_RATIO;
	camera.focal_len = 1;
	camera.horizontal = vmult_k(u, camera.viewport_w);
	camera.vertical = vmult_k(v, camera.viewport_h);
	camera.left_top = get_left_top(&camera, w);
	scene->camera = camera;
}
