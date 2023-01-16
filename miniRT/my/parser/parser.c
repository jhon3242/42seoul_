/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeyhan <chaeyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:09 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/16 16:24:09 by chaeyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	check_file_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strcmp(extension, ".rt"))
		exit_with_error("Invalid file extension\n");
}

char	**file_parser(char *filename)
{
	int		fd;
	int		count;
	char	**line;
	char	*raw_data;

	count = get_file_size(filename);
	fd = ft_open(filename, O_RDONLY);
	raw_data = (char *)ft_malloc(sizeof(char) * (count + 1));
	read(fd, raw_data, count);
	raw_data[count] = '\0';
	validate_rt(raw_data);
	close(fd);
	line = ft_split(raw_data, '\n');
	free(raw_data);
	return (line);
}

void	object_parser(char **line, t_scene *scene)
{
	char	**data;

	while (*line)
	{
		data = ft_split(*line, ' ');
		if (!ft_strcmp(data[0], "A"))
			ambient(scene, data);
		else if (!ft_strcmp(data[0], "C"))
			camera(scene, data);
		else if (!ft_strcmp(data[0], "L"))
			light(scene, data);
		else if (!ft_strcmp(data[0], "sp"))
			sphere(scene, data);
		else if (!ft_strcmp(data[0], "pl"))
			plane(scene, data);
		else if (!ft_strcmp(data[0], "cy"))
			cylinder(scene, data);
		free_split(data);
	}
}

void	parse(t_scene *scene, char *filename)
{
	char	**line;
	
	scene->object_list = 0;
	scene->light_list = 0;
	check_file_extension(filename);
	line = file_parser(filename);
	object_parser(line, scene);
	free_split(line);
}