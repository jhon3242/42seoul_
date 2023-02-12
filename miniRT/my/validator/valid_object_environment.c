/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_object_environment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeyhan <chaeyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:16:42 by chaeyhan          #+#    #+#             */
/*   Updated: 2023/02/12 15:53:15 by chaeyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	check_theta(char *str)
{
	double	theta;

	check_double(str);
	theta = ft_atod(str);
	if (theta < 0 || theta > 180)
		exit_with_error("theta must be 0 <= theta <= 180\n");
}

void	check_object_ambient(char *str)
{
	char	**elements;

	elements = ft_split(str, ' ');
	check_invalid_char(&str[1], "0123456789.,- ");
	check_elements_cnt(elements, 3);
	check_double(elements[1]);
	check_color3(elements[2]);
	count_ambient();
	free_split(elements);
}

void	check_object_camera(char *str)
{
	char	**elements;

	elements = ft_split(str, ' ');
	check_invalid_char(&str[1], "0123456789.,- ");
	check_elements_cnt(elements, 4);
	check_vec3(elements[1]);
	check_vec3(elements[2]);
	if (vlength(parse_vec3(elements[2])) == 0)
		exit_with_error("Invalid vector\n");
	check_theta(elements[3]);
	count_camera();
	free_split(elements);
}

void	check_object_light(char *str)
{
	char	**elements;

	elements = ft_split(str, ' ');
	check_invalid_char(&str[1], "0123456789.,- ");
	check_elements_cnt(elements, 3);
	check_vec3(elements[1]);
	check_double(elements[2]);
	count_light();
	free_split(elements);
}
