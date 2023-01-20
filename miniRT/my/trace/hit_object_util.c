/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obeject_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:38:43 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/20 17:38:59 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	t_bool	front_face;

	front_face = vdot(r->dir, rec->normal) < 0;
	if (!front_face)
		rec->normal = vmult_k(rec->normal, -1);
}