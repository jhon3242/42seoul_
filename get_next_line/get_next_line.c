/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:25:04 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/01/02 22:00:05 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 50

#include <fcntl.h>
#include <stdio.h>

static int newline_ck(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static renew_backup(char **backup, int fd, char *buff)
{
	int	len;

	len = 1;
	while (len != 0 && )
	{
		backup[fd] = ft_strjoin(backup[fd], buff);
	}

}

char *get_next_line(int fd)
{
	static char		*backup[OPEN_MAX];
	char			buff[BUFFER_SIZE + 1];
	ssize_t			len;
	int				newline_idx;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	if (!renew_backup())
		return (0);
}
