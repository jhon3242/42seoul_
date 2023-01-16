/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeyhan <chaeyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:17:44 by chaeyhan          #+#    #+#             */
/*   Updated: 2023/01/16 16:20:22 by chaeyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	check_object_sp(char *str)
{
	char	**column;

	column = ft_split(str, ' ');
	check_invalid_char(&str[2], "0123456789.,- ");
	check_elements_cnt(column, 4);
	check_vec3(column[1]);
	check_double(column[2]);
	check_color3(column[3]);
	free_split(column);
}

void	check_object_pl(char *str)
{
	char	**column;

	column = ft_split(str, ' ');
	check_invalid_char(&str[2], "0123456789.,- ");
	check_elements_cnt(column, 4);
	check_vec3(column[1]);
	check_vec3(column[2]);
	check_color3(column[3]);
	free_split(column);
}

void	check_object_cy(char *str)
{
	char	**column;

	column = ft_split(str, ' ');
	check_invalid_char(&str[2], "0123456789.,- ");
	check_elements_cnt(column, 6);
	check_vec3(column[1]);
	check_vec3(column[2]);
	check_double(column[3]);
	check_double(column[4]);
	check_color3(column[5]);
	free_split(column);
}