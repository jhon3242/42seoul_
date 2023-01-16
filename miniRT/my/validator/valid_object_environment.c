/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_object_environment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeyhan <chaeyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:16:42 by chaeyhan          #+#    #+#             */
/*   Updated: 2023/01/16 15:59:29 by chaeyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	check_object_ambient(char *str)
{
	char	**elements;

	elements = ft_split(str, ' ');
	check_invalid_char(&str[1], "0123456789.,- ");
	check_elements_cnt(elements, 3);
	check_double(elements[1], DOUBLE_CHAR);
	check_color3(elements[2], COLOR_CHAR);
	count_ambient();
	free_split(elements);
}