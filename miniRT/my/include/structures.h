/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:36 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/11 15:09:01 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define MLX_WIDTH	800
# define MLX_HEIGHT	600
# define MLX_RATIO	1.333334
# define EPSILON		1e-6

# define ESC				53
# define X_EVENT_KEY_EXIT	17


typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_color3;
typedef struct s_vec3		t_point3;
typedef struct s_mlx		t_mlx;
typedef struct s_scene		t_scene;
typedef struct s_object		t_object;
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;

typedef enum	e_object_type
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
	t_point3	orig;
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
	double	canvas_ratio; // TODO ??
};

struct s_scene
{
	t_mlx			mlx;
	t_camera		camera;
	t_object		*object_list;
	t_object		*light_list;
	t_ambient		ambient;
	// t_ray			ray;
	// t_hit_record	rec;
};

#endif