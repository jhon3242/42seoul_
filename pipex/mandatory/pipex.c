/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 23:10:18 by choewonjun        #+#    #+#             */
/*   Updated: 2022/08/20 13:36:55 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	operation(t_info *info)
{
	info->splited_cmd = ft_split(info->argv[info->count], ' ');
	if (info->splited_cmd == NULL)
		error_exit("Ft_split Error", EXIT_FAILURE);
	info->path_cmd = get_path_cmd(info->path_envp, info->splited_cmd[0]);
	if (info->path_cmd == NULL)
		error_exit("Command not found Error", EXIT_FAILURE);
	close_unused_fd(info);
	if (execve(info->path_cmd, info->splited_cmd, info->envp) == 0)
		error_exit("Execve Error", EXIT_FAILURE);
}

void	fork_with_exec(t_info *info)
{
	while (info->count < info->argc - 1)
	{
		if (pipe(info->b) < 0)
			error_exit("Pipe error", EXIT_FAILURE);
		redirect(info);
		info->pid = fork();
		if (info->pid < 0)
			error_exit("Fork error", EXIT_FAILURE);
		else if (info->pid == 0)
			operation(info);
		else
		{
			close_unused_fd(info);
			info->a[READ] = info->b[READ];
			info->count++;
		}
	}
}

void	init(t_info *info, int argc, char **argv, char **envp)
{
	info->argc = argc;
	info->argv = argv;
	info->envp = envp;
	info->first_arg = argv[1];
	info->last_arg = argv[argc - 1];
	info->path_envp = get_path_envp(envp);
	if (info->path_envp == 0)
		error_exit("PATH Error.", EXIT_FAILURE);
	info->count = 2;
	info->open_flag = O_RDWR | O_CREAT | O_TRUNC;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_info	info;

	if (argc != 5)
		error_exit("Wrong argument.", EXIT_FAILURE);
	if (pipe(info.a) < 0)
		error_exit("Pipe error.", EXIT_FAILURE);
	init(&info, argc, argv, envp);
	fork_with_exec(&info);
}
