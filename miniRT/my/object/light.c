/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:38:29 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/02/07 13:37:33 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	light(t_scene *scene, char **data)
{
	t_light	*light;

	light = ft_malloc(sizeof(t_light));
	light->origin = parse_vec3(data[1]);
	light->bright_ratio = ft_atod(data[2]);
	light->light_color = vec3(1, 1, 1);
	oadd(&(scene->light_list), object(light, LIGHT_POINT));
}
