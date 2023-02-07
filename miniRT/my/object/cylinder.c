/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:14:19 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/02/07 13:37:22 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	cylinder(t_scene *scene, char **data)
{
	t_cylinder	*cylinder;

	cylinder = ft_malloc(sizeof(t_cylinder));
	cylinder->point = parse_vec3(data[1]);
	cylinder->normal = vunit(parse_vec3(data[2]));
	cylinder->radius = ft_atod(data[3]) / 2;
	cylinder->height = ft_atod(data[4]);
	cylinder->color = parse_color(data[5]);
	oadd(&(scene->object_list), object(cylinder, CY));
}
