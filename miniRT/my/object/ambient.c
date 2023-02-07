/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:09:22 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/02/07 13:37:26 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	ambient(t_scene *scene, char **data)
{
	t_ambient	ambient;

	ambient.ambient = ft_atod(data[1]);
	ambient.color = parse_color(data[2]);
	scene->ambient = ambient;
}
