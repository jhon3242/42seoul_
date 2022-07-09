/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:46:15 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/07/09 21:05:52 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_fd(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("failed file open.");
	return (fd);
}

void	get_map_chunks(t_game *game, const char *path)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*sentance;

	fd = get_fd(path);
	sentance = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strjoin(sentance, line);
		free(line);
		if (!tmp)
			print_error("failed map reading.");
		free(sentance);
		sentance = tmp;
	}
	game->map.chunks = ft_split(sentance, '\n');
	free(sentance);
	if (!game->map.chunks || !game->map.chunks[0])
		print_error("failed map reading.");
}

void	get_map_size(t_map *map)
{
	int	i;

	i = 0;
	while (map->chunks[i])
		i++;
	map->size.x = i;
	map->size.y = ft_strlen(map->chunks[0]);
}
