/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_object_environment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:16:42 by chaeyhan          #+#    #+#             */
/*   Updated: 2023/01/18 13:33:08 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	check_object_ambient(char *str) // str = "A 0.2 255,255,255"
{
	char	**column;

	column = ft_split(str, ' ');
	check_object_position(&str[1]);
	check_column_cnt(column, 3);
	check_double(column[1]);
	check_color3(column[2]);
	count_ambient();
	free_split(column);
}

void	check_object_camera(char *str)
{
	char	**column;

	column = ft_split(str, ' ');
	check_object_position(&str[1]);
	check_column_cnt(column, 4);
	check_vec3(column[1]);
	check_vec3(column[2]);
	if (vlength(str_to_vec3(column[2])) == 0)
		exit_with_error("invalid vector\n");
	check_theta(column[3]);
	count_camera();
	free_split(column);
}

void	check_object_light(char *str)
{
	char	**column;

	column = ft_split(str, ' ');
	check_object_position(&str[1]);
	check_column_cnt(column, 3);
	check_vec3(column[1]);
	check_double(column[2]);
	count_light();
	free_split(column);
}
