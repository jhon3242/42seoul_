/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:39 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/09 15:00:17 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "structures.h"
# include "ft_open.h"
# include "mlx.h"

/* 
			util.c
*/
void		exit_with_error(char *msg);
int			get_file_size(char *filename);

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
			mlx
*/
int 		mlx_esc_exit(int keycode, t_mlx *mlx);
int			mlx_exit(t_mlx *mlx);
void		set_mlx(t_mlx *mlx);

/*
			parser
*/
void		parse(t_scene *scene, char *filename);

#endif