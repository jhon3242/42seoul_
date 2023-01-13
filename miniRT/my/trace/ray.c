/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:14:04 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/13 14:59:57 by wonjchoi         ###   ########.fr       */
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

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3 at;

	at = vplus(ray->origin, vmult_k(ray->dir, t));
	return (at);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam->origin;
	ray.dir = vunit(vminus(vplus(vplus(cam->left_top, \
		vmult_k(cam->horizontal, u)), \
		vmult_k(cam->vertical, v)), cam->origin));
	return (ray);
}

t_color3	ray_color(t_scene *scene)
{
	scene->rec = record_init();
	if (hit(scene->object_list, &(scene->ray), &(scene->rec)))
		return color3(0,0,0); // TODO
}