/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:39 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/18 13:34:58 by wonjchoi         ###   ########.fr       */
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

void	check_object_position(char *str);
void	check_column_cnt(char **column, int column_cnt);
void	check_theta(char *str);
t_vec3	str_to_vec3(char *data);
t_color3	parse_color(char *data);
double	a_to_d(const char *str);
void	*wrap_malloc(size_t size);
int	ft_atoi(const char *str);
/* 
			util.c
*/
void		exit_with_error(char *msg);
int			get_file_size(char *filename);
void		free_split(char **data);

// int			ft_open(const char *path, int flags);
int wrap_open(const char *path, int flags);

/*
			util_object.c
*/
double		maxf(double a, double b);
double		minf(double a, double b);


/*
			util_libft.c
*/
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
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
			validator
*/
void		set_filter(int *filter, const char *valid_str);

void		check_invalid_char(char *str, char *valid_char);
void		validate_rt(char *str);

int 		count_ambient(void);
int 		count_light(void);
int 		count_camera(void);

void		check_elements_cnt(char **elements, int cnt);
void		check_double(char *str);
void		check_color3(char *str);
void		check_vec3(char *str);

void		check_object_ambient(char *str);
void		check_object_camera(char *str);
void		check_object_light(char *str);

void		check_object_sp(char *str);
void		check_object_pl(char *str);
void		check_object_cy(char *str);

/*
			trace
*/
t_bool		hit_obj(t_object *object_list, t_ray *ray, t_hit_record *rec);
t_bool		hit(t_object *object_list, t_ray *ray, t_hit_record *rec);

t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_scene *scene);
t_bool		hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec);

#endif