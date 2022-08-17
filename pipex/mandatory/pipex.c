/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 23:10:18 by choewonjun        #+#    #+#             */
/*   Updated: 2022/08/17 20:53:42 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void operation(t_info *info)
{
	info->cmd_options = ft_split(info->argv[info->count], ' ');
	if (info->cmd_options == NULL)
		error_exit("Ft_split Error", EXIT_FAILURE);
	info->path_cmd = 
}

void fork_with_exec(t_info *info)
{
	if (pipe(info->b) < 0)
		error_exit("Pipe error", EXIT_FAILURE);
	redirect(info);
	info->pid = fork();
	if (info->pid < 0)
		error_exit("Fork error", EXIT_FAILURE);
	else if (info->pid == 0) // 자식
		operation(info);
	else
	{
		
	}
}

void    init(t_info *info, int argc, char **argv, char **envp)
{
	info->argc = argc;
	info->argv = argv;
	info->envp = envp;
	info->first_arg = argv[1];
	info->count = 2;
}

int main(int argc, char *argv[], char *envp[])
{   
	t_info  info;

	if (argc != 5)
		error_exit("Wrong argument.", EXIT_FAILURE);
	if (pipe(info.a) < 0)
		error_exit("Pipe error.", EXIT_FAILURE);
	init(&info, argc, argv, envp);
	fork_with_exec(&info);
}