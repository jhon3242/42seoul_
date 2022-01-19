/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:25:04 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/01/18 10:26:58 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	count_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	char	find;
	int		i;

	find = (char)c;
	i = -1;
	while (s[++i])
	{
		if (s[i] == find)
			return ((char *)s + i);
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

static char	*split_str(char **backup, int fd)
{
	int		len;
	char	*ret;
	char	*new;

	if (*backup[fd] == 0)
	{
		free(backup[fd]);
		backup[fd] = 0;
		return (0);
	}
	len = count_len(backup[fd]);
	ret = ft_substr(backup[fd], 0, len + 1);
	if (ret == 0)
		return (0);
	new = ft_substr(backup[fd], len + 1, ft_strlen(backup[fd]) - (len + 1));
	if (new == 0)
	{
		free(ret);
		return (0);
	}
	free(backup[fd]);
	backup[fd] = new;
	return (ret);
}

static int	update_backup(char **backup, int fd, char *buff)
{
	int	len;

	len = 1;
	while (len != 0 && !ft_strchr(backup[fd], '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len < 0)
		{
			free(backup[fd]);
			free(buff);
			return (0);
		}
		buff[len] = 0;
		backup[fd] = ft_strjoin(backup[fd], buff);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*backup[10240];
	char			*buff;

	if (fd < 0 || fd >= 10240 || BUFFER_SIZE < 1)
		return (0);
	if (backup[fd] == 0)
		backup[fd] = ft_strdup("");
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		free(backup[fd]);
		return (0);
	}
	if (!update_backup(backup, fd, buff))
		return (0);
	free(buff);
	return (split_str(backup, fd));
}
