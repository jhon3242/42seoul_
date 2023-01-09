/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:36 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/09 14:30:50 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define MLX_WIDTH	800
# define MLX_HEIGHT	600
# define MLX_RATIO	1.333334

# define ESC				53
# define X_EVENT_KEY_EXIT	17


typedef struct s_mlx		t_mlx;
typedef struct s_scene		t_scene;
typedef struct s_object		t_object;

typedef enum	e_object_type
{
	SP,
	PL,
	CY,
	CO,
	LIGHT_POINT,
	AMBIENT,
}				t_object_type;

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
	t_mlx		mlx;
	t_object	*object_list;
	t_object	*light_list;
};

#endif