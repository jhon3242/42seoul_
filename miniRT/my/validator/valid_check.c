/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:18:09 by chaeyhan          #+#    #+#             */
/*   Updated: 2023/02/07 13:52:36 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	check_elements_cnt(char **elements, int cnt)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (i != cnt)
		exit_with_error("Invalid elements count\n");
}

void	check_double(char *str)
{
	int	filter[128];

	set_filter(filter, DOUBLE_CHAR);
	if (str[0] == '-')
		str++;
	while (*str)
	{
		if (filter[(int)*str] == 0)
			exit_with_error("Invalid double format\n");
		if (*str == '.')
			filter[(int)*str] -= 1;
		str++;
	}
}

void	check_color3(char *str)
{
	char	**color3;
	int		filter[128];
	int		i;
	int		tmp;

	set_filter(filter, COLOR_CHAR);
	i = -1;
	while (str[++i])
	{
		if (filter[(int)str[i]] == 0)
			exit_with_error("Invalid RGB format\n");
		if (str[i] == ',')
			filter[(int)str[i]] -= 1;
	}
	color3 = ft_split(str, ',');
	check_elements_cnt(color3, 3);
	i = -1;
	while (++i < 3)
	{
		tmp = ft_atoi(color3[i]);
		if (tmp < 0 || tmp > 255)
			exit_with_error("Invalid RGB number\n");
	}
	free_split(color3);
}

void	check_vec3(char *str)
{
	char	**vec3;
	int		i;

	vec3 = ft_split(str, ',');
	check_elements_cnt(vec3, 3);
	i = -1;
	while (++i < 3)
		check_double(vec3[i]);
	free_split(vec3);
}
