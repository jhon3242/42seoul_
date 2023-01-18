/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:00:51 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/18 14:08:34 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static t_bool	set_root(double a, double half_b, double c, t_hit_record *rec)
{
	double	discriminant;
	double	sqrtd;
	double	root;

	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = minf((-half_b - sqrtd) / a, (-half_b + sqrtd) / a);
	if (root < rec->tmin || rec->tmax < root)
	{
		root = maxf((-half_b - sqrtd) / a, (-half_b + sqrtd) / a);
		if (root < rec->tmin || root > rec->tmax)
			return (FALSE);
	}
	rec->t = root;
	return (TRUE);
}

static t_bool	hit_circle(const t_cylinder *cy,
					t_ray *ray, t_hit_record *rec, int position)
{
	t_vec3		normal;
	t_point3	center;
	double		denominator;
	double		numerator;
	double		root;

	normal = vmult_k(cy->normal, position);
	center = vplus(cy->point, vmult_k(cy->normal, cy->height / 2));
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
	return (TRUE);
}

t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_vec3		po_c;
	t_vec3		cp;

	cy = cy_obj->element;
	po_c = vcross(vminus(ray->origin, cy->point), cy->normal);
	if (!set_root(vlength2(vcross(ray->dir, cy->normal)),
			vdot(vcross(ray->dir, cy->normal), po_c),
			vlength2(po_c) - cy->radius* cy->radius, rec))
		return (FALSE);
	rec->p = ray_at(ray, rec->t);
	cp = vminus(rec->p, cy->point);
	if (fabs(vdot(cp, cy->normal)) > cy->height / 2)
		return (hit_circle(cy, ray, rec, TOP) || 
			hit_circle(cy, ray, rec, BOTTOM));
	rec->normal = vunit(vminus(cp, vmult_k(cy->normal, vdot(cp, cy->normal))));
	rec->color = cy->color;
	return (TRUE);
}

