/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:09 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/09 14:27:36 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	**file_parser(char *filename)
{
	int		fd;
	int		count;
	char	**line;

	count = get_file_size(filename);

	return 0;
}

void	check_file_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strcmp(extension, ".rt"))
		exit_with_error("Invalid file extension\n");
}

void	parse(t_scene *scene, char *filename)
{
	char	**line;
	
	scene->object_list = 0;
	scene->light_list = 0;
	check_file_extension(filename);
	line = file_parser(filename);
}