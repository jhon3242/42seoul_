/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:54:29 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/13 15:08:56 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_bool	hit_obj(t_object *object_list, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (object_list->type == SP)
		hit_result = hit_sphere(object_list, ray, rec);
	else if (object_list->type == PL)
		hit_result = hit_plane(object_list, ray, rec);
	return (hit_result);
}

t_bool	hit(t_object *object_list, t_ray *ray, t_hit_record *rec)
{
	t_hit_record	tmp_rec;
	t_bool			hit_anything;
	
	tmp_rec = *rec;
	hit_anything = FALSE;
	while (object_list)
	{
		if (hit_obj(object_list, ray, &tmp_rec))
		{
			hit_anything = TRUE;
			tmp_rec.tmax = tmp_rec.t;
			*rec = tmp_rec;
		}
		object_list = object_list->next;
	}
	return (hit_anything);
}