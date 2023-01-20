/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:24 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/18 13:36:15 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void exit_with_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	get_file_size(char *filename)
{
	int		fd;
	int		read_byte;
	int		count;
	char	buff[1024];

	fd = wrap_open(filename, O_RDONLY);
	read_byte = 1;
	while (read_byte)
	{
		read_byte = read(fd, buff, 1024);
		count += read_byte;
	}
	close(fd);
	return count;;
}

void	free_split(char **data)
{
	char	**cur;

	cur = data;
	while (*cur)
	{
		free(*cur);
		cur++;
	}
	free(data);
}