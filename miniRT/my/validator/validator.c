/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeyhan <chaeyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:56:21 by chaeyhan          #+#    #+#             */
/*   Updated: 2023/02/12 15:28:21 by chaeyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	parse_object(char *str)
{
	char	**line;
	int		i;

	line = ft_split(str, '\n');
	i = -1;
	while (line[++i])
	{
		if (line[i][0] == 'A')
			check_object_ambient(line[i]);
		else if (line[i][0] == 'C')
			check_object_camera(line[i]);
		else if (line[i][0] == 'L')
			check_object_light(line[i]);
		else if (line[i][0] == 's' && line[i][1] == 'p')
			check_object_sp(line[i]);
		else if (line[i][0] == 'p' && line[i][1] == 'l')
			check_object_pl(line[i]);
		else if (line[i][0] == 'c' && line[i][1] == 'y')
			check_object_cy(line[i]);
		else
			exit_with_error("Invalid object\n");
	}
	free_split(line);
}

void	check_invalid_char(char *str, char *valid_char)
{
	int	filter[128];

	set_filter(filter, valid_char);
	while (*str)
	{
		if (filter[(int)*str] == 0)
			exit_with_error("Invalid .rt format\n");
		str++;
	}
}

void	validate_rt(char *str)
{
	check_invalid_char(str, "ACLsplcy0123456789.,- \n");
	parse_object(str);
	if (count_ambient() != 1
			|| count_camera() != 1
			|| count_light() != 1)
		exit_with_error("Invalid object count\n");
}
