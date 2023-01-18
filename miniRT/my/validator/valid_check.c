/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:18:09 by chaeyhan          #+#    #+#             */
/*   Updated: 2023/01/18 13:32:24 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	check_elements_cnt(char **elements, int cnt)
{
	int	i;
	
	i = 0;
	while(elements[i]){
		i++;
	}
	if (i != cnt)
		exit_with_error("Invalid elements count\n");
}

void	check_object_position(char *str)
{
	const char	*valid_char = "0123456789.,- ";
	int			filter[128];

	set_filter(filter, valid_char);
	while (*str)
	{
		if (filter[(int)*str] == 0)
			exit_with_error("invalid .rt format\n");
		str++;
	}
}

void	check_column_cnt(char **column, int column_cnt)
{
	int	cnt;

	cnt = 0;
	while (column[cnt])
		cnt++;
	if (cnt != column_cnt)
		exit_with_error("invalid .rt format\n");
}

void	check_theta(char *str)
{
	double	theta;

	check_double(str);
	theta = a_to_d(str);
	if (theta < 0 || theta > 180)
		exit_with_error("theta must be 0 <= theta <= 180\n");
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