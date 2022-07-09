/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:38:10 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/07/09 21:07:08 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_path(const char *path, const char *suffix)
{
	int	p_len;
	int	s_len;

	p_len = ft_strlen(path);
	s_len = ft_strlen(suffix);
	if (p_len < 4)
		print_error("invalid file path.");
	if (ft_strncmp(suffix, &path[p_len - s_len], s_len))
		print_error("invalid file type.");
}

void	check_shape(t_map *map)
{
	int	x;
	int	y_len;

	x = 0;
	while (x < map->size.x)
	{
		y_len = ft_strlen(map->chunks[x]);
		if (map->size.y != y_len)
			print_error("Invalid map shape.");
		x++;
	}
}

void	check_surround(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.y)
	{
		if (map->chunks[0][i] != '1')
			print_error("Top of map is not surrounded by wall.");
		if (map->chunks[map->size.x - 1][i] != '1')
			print_error("Bottom of map is not surrounded by wall.");
		i++;
	}
	i = 0;
	while (i < map->size.x)
	{
		if (map->chunks[i][0] != '1')
			print_error("Left of map is not surrounded by wall.");
		if (map->chunks[i][map->size.y - 1] != '1')
			print_error("Right of map is not surrounded by wall.");
		i++;
	}
}

void	check_component(t_map *map)
{
	const char	*componets = "10PCE";
	int			x;
	int			y;

	ft_bzero(&map->flags, sizeof(map->flags));
	x = 0;
	while (x < map->size.x)
	{
		y = 0;
		while (y < map->size.y)
		{
			if (!ft_strchr(componets, map->chunks[x][y]))
				print_error("Invalid component.");
			if (map->chunks[x][y] == 'C')
				map->flags.item++;
			else if (map->chunks[x][y] == 'E')
				map->flags.exit++;
			else if (map->chunks[x][y] == 'P')
				map->flags.player++;
			y++;
		}
		x++;
	}
	if (map->flags.exit < 1 || map->flags.item < 1 || map->flags.player != 1)
		print_error("insufficient count of component");
}
