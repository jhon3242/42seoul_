/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:38:34 by choewonjun        #+#    #+#             */
/*   Updated: 2022/08/20 15:23:31 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_exit(const char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

void	dup2_with_errorck(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		error_exit("dup2 Error", EXIT_FAILURE);
}

void	close_with_errorck(int fd)
{
	if (close(fd) == -1)
		error_exit("Close Error", EXIT_FAILURE);
}

void	write_with_errorck(int fd, char *str, size_t len)
{
	if (write(fd, str, len) == -1)
		error_exit("Write Error", EXIT_FAILURE);
}