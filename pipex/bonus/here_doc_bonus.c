/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:06:31 by choewonjun        #+#    #+#             */
/*   Updated: 2022/08/20 17:51:34 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	get_here_doc_input(t_info *info)
{
	char	*limiter;
	char	*line;
	size_t	len;

	limiter = info->argv[2];
	len = ft_strlen(limiter);
	while (1)
	{
		write_with_errorck(STDOUT_FILENO, "pipe here_doc > ", 16);
		line = get_next_line(STDIN_FILENO);
		if (ft_strlen(line) - 1 == len && ft_strncmp(line, limiter, len) == 0)
		{
			free(line);
			close_unused_fd(info);
			exit(EXIT_SUCCESS);
		}
		write_with_errorck(info->b[WRITE], line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(t_info *info)
{
	if (ft_strlen(info->first_arg) != 8 || ft_strncmp(info->first_arg, "here_doc", 8))
		return ;
	if (pipe(info->b) < 0)
		error_exit("Pipe Error", EXIT_FAILURE);
	info->pid = fork();
	if (info->pid < 0)
		error_exit("Fork Error", EXIT_FAILURE);
	else if (info->pid == 0)
		get_here_doc_input(info);
	else
	{
		close_unused_fd(info);
		info->a[READ] = info->b[READ];
		info->open_flag = O_WRONLY | O_CREAT | O_APPEND;
		info->count = 3;
	}
}