/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:36 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/02/07 13:34:06 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define MLX_WIDTH			800
# define MLX_HEIGHT			600
# define MLX_RATIO			1.333334
# define EPSILON			1e-6
# define LUMEN				2

# define ESC				53
# define X_EVENT_KEY_EXIT	17

# define FALSE				0
# define TRUE				1

# define TOP				1
# define BOTTOM				-1

# define DOUBLE_CHAR		"0123456789."
# define COLOR_CHAR 		"0123456789,,"

typedef struct s_vec3			t_vec3;
typedef struct s_vec3			t_color3;
typedef struct s_vec3			t_point3;

typedef struct s_object			t_object;
typedef struct s_ambient		t_ambient;
typedef struct s_camera			t_camera;
typedef struct s_light			t_light;
typedef struct s_sphere			t_sphere;
typedef struct s_plane			t_plane;
typedef struct s_cylinder		t_cylinder;

typedef struct s_mlx			t_mlx;
typedef struct s_ray			t_ray;
typedef struct s_hit_record		t_hit_record;

typedef struct s_scene			t_scene;

typedef int						t_bool;

typedef enum e_object_type
{
	SP,
	PL,
	CY,
	CO,
	LIGHT_POINT,
	AMBIENT,
}				t_object_type;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_ambient
{
	double		ambient;
	t_color3	color;
};

struct s_camera
{
	t_point3	origin;
	t_vec3		camera_dir;
	double		focal_len;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_point3	left_top;
};

struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

struct s_sphere
{
	t_point3	center;
	t_color3	color;
	double		radius;
	double		radius_pow_2;
};

struct s_plane
{
	t_point3	center;
	t_vec3		normal;
	t_color3	color;
};

struct s_cylinder
{
	t_point3	point;
	t_vec3		normal;
	t_color3	color;
	double		radius;
	double		height;
};

struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		width;
	int		height;
	int		line_length;
	double	canvas_ratio;
};

struct s_ray
{
	t_point3	origin;
	t_vec3		dir;
};

struct s_hit_record
{
	t_point3	p;
	t_color3	color;
	t_vec3		normal;
	double		t;
	double		tmin;
	double		tmax;
};

struct s_scene
{
	t_mlx			mlx;
	t_camera		camera;
	t_object		*object_list;
	t_object		*light_list;
	t_ambient		ambient;
	t_ray			ray;
	t_hit_record	rec;
};

#endif