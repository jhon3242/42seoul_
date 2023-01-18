/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:07:11 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/18 16:49:28 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	plane(t_scene *scene, char **data)
{
	t_plane *plane;

	plane = ft_malloc(sizeof(t_plane));
	plane->center = parse_vec3(data[1]);
	plane->normal = vunit(parse_vec3(data[2]));
	plane->color = parse_color(data[3]);
	oadd(&(scene->object_list), object(plane, PL));
}