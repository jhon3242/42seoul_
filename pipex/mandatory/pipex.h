/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 23:10:42 by choewonjun        #+#    #+#             */
/*   Updated: 2022/08/17 21:27:47 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ 0
# define WRITE 1

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../lib/libft/include/libft.h"


typedef struct  s_info
{
	int		argc;
	char	**argv;
	char	**envp;
	char	*first_arg;
	int		a[2];
	int		b[2];
	int		count;
	int		pid;
	char	**cmd_options;
	char	*path_cmd;
}			t_info;


/* error_handling.c
========================================================== */
void	error_exit(const char *msg, int exit_code);
void	dup2_with_errorck(int fd1, int fd2);
void	close_with_errorck(int fd);

/* fd_handling.c
========================================================== */
void	redirect(t_info *info);

# endif

