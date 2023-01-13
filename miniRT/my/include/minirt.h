/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:39 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/13 15:00:15 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "structures.h"
# include "ft_open.h"
# include "mlx.h"
# include "vector.h"

/* 
			util.c
*/
void		exit_with_error(char *msg);
int			get_file_size(char *filename);
void		free_split(char **data);

void		*ft_malloc(size_t size);
int			ft_open(const char *path, int flags);

/*
			util_object.c
*/
t_vec3		parse_vec3(char *data);
t_color3	parse_color(char *data);
double		ft_atod(const char *str);
double		maxf(double a, double b);
double		minf(double a, double b);


/*
			util_libft.c
*/
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_atoi(const char *str);
int			ft_strcmp(char *line, char *c);
char		*ft_strrchr(const char *s, int c);
char		**ft_split(char const *s, char c);


/*
			object
*/
void		ambient(t_scene *scene, char **data);
void		camera(t_scene *scene, char **data);
void		light(t_scene *scene, char **data);
void		sphere(t_scene *scene, char **data);
void		plane(t_scene *scene, char **data);
void		cylinder(t_scene *scene, char **data);
void		oadd(t_object **list, t_object *new_obj);
t_object	*object(void *object, int type);


/*
			mlx
*/
int 		mlx_esc_exit(int keycode, t_mlx *mlx);
int			mlx_exit(t_mlx *mlx);
void		set_mlx(t_mlx *mlx);
void		drawing(t_scene *scene);

/*
			parser
*/
void		parse(t_scene *scene, char *filename);


/*
			trace
*/
t_bool		hit_obj(t_object *object_list, t_ray *ray, t_hit_record *rec);
t_bool		hit(t_object *object_list, t_ray *ray, t_hit_record *rec);

t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_scene *scene);
t_bool		hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec);

#endif