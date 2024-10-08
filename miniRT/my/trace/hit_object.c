/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:16:21 by chaeyhan          #+#    #+#             */
/*   Updated: 2023/02/07 13:46:15 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_bool	set_root(double a, double half_b, double c, t_hit_record *rec)
{
	double	root;
	double	discriminant;
	double	sqrtd;

	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = minf((-half_b - sqrtd) / a, (-half_b + sqrtd) / a);
	if (root < rec->tmin || rec->tmax < root)
	{
		root = maxf((-half_b - sqrtd) / a, (-half_b + sqrtd) / a);
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	return (TRUE);
}

t_bool	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;

	sp = sp_obj->element;
	oc = vminus(ray->origin, sp->center);
	a = vlength2(ray->dir);
	half_b = vdot(oc, ray->dir);
	c = vlength2(oc) - sp->radius_pow_2;
	if (!set_root(a, half_b, c, rec))
		return (FALSE);
	rec->p = ray_at(ray, rec->t);
	rec->color = sp->color;
	rec->normal = vunit(vminus(rec->p, sp->center));
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	double	denominator;
	double	numerator;
	double	root;

	pl = pl_obj->element;
	denominator = vdot(pl->normal, ray->dir);
	if (fabs(denominator) < EPSILON)
		return (FALSE);
	numerator = vdot(vminus(pl->center, ray->origin), pl->normal);
	root = numerator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->color = pl->color;
	rec->normal = pl->normal;
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_circle(const t_cylinder *cy,
					t_ray *ray, t_hit_record *rec, int position)
{
	double		denominator;
	double		numerator;
	double		root;
	t_vec3		normal;
	t_point3	center;

	normal = vmult_k(cy->normal, position);
	center = vplus(cy->point, vmult_k(normal, cy->height / 2));
	denominator = vdot(normal, ray->dir);
	if (fabs(denominator) < EPSILON)
		return (FALSE);
	numerator = vdot(vminus(center, ray->origin), normal);
	root = numerator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->color = cy->color;
	rec->normal = normal;
	if (vlength(vminus(rec->p, center)) - cy->radius > EPSILON)
		return (FALSE);
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	const t_cylinder	*cy = cy_obj->element;
	const t_vec3		uo_c = vcross(ray->dir, cy->normal);
	const t_vec3		po_c = vcross(vminus(ray->origin, cy->point), \
												cy->normal);
	t_vec3				cp;

	if (!set_root(
			vlength2(uo_c),
			vdot(uo_c, po_c),
			vlength2(po_c) - cy->radius * cy->radius,
			rec))
		return (FALSE);
	rec->p = ray_at(ray, rec->t);
	cp = vminus(rec->p, cy->point);
	if (fabs(vdot(cp, cy->normal)) > cy->height / 2)
		return (hit_circle(cy, ray, rec, TOP)
			|| hit_circle(cy, ray, rec, BOTTOM));
	rec->normal = vunit(vminus(cp, vmult_k(cy->normal, vdot(cp, cy->normal))));
	rec->color = cy->color;
	set_face_normal(ray, rec);
	return (TRUE);
}
