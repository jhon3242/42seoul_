/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:14:04 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/20 16:48:55 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static t_hit_record	record_init(void)
{
	t_hit_record	record;
	
	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_ray	ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3 at;

	at = vplus(ray->orig, vmult_k(ray->dir, t));
	return (at);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = vunit(vminus(vplus(vplus(cam->left_top, \
		vmult_k(cam->horizontal, u)), \
		vmult_k(cam->vertical, v)), cam->orig));
	return (ray);
}

t_color3	ray_color(t_scene *scene)
{
	scene->rec = record_init();
	if (hit(scene->object_list, &scene->ray, &scene->rec))
		return phong_lighting(scene); // TODO
	else
		return color3(1, 1, 1);
}