#include "microshell.h"

int init_cmd_info(char **av, t_cmd_info *info, int i)
{
	info->path = av[i];
	info->av = &av[i];
	info->prev_type = info->curr_type;
	while (1) {
		if (av[i + 1] == NULL \
		|| strncmp(av[i + 1], ";", 2) == 0\
		|| strncmp(av[i + 1], "|", 2) == 0)
		{
			if (av[i + 1] == NULL)
				info->curr_type = kNull;
			else if (strncmp(av[i + 1], "|", 2) == 0)
				info->curr_type = kPipe;
			else
				info->curr_type = kSemicolon;

			av[i + 1] = NULL;
			i++;
			break;
		}
		i++;
	}
	return (i);
}

int ft_strlen(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void write_err(const char *str)
{
	write(2, str, ft_strlen(str));
}

void system_err()
{
	write_err("error: fatal");
	exit(1);
}

void wait_all_process(int cnt)
{
	int ret;

	for(int i =0; i<cnt; i++)
	{
		ret = waitpid(-1, NULL, 0);
		if (ret == -1)
			system_err();
	}
}

void safe_dup2_and_close(int old, int new)
{
	int ret;

	ret = dup2(old, new);
	if (ret == -1)
		system_err();
	close(old);
}

void do_it_child(t_cmd_info *info, t_pipe_info *pipe_info)
{
	if (info->curr_type == kPipe)
	{
		close(pipe_info->curr_pipe[0]);
		safe_dup2_and_close(pipe_info->curr_pipe[1], 1);
	}
	if (info->prev_type == kPipe)
	{
		safe_dup2_and_close(pipe_info->prev_read_pipe, 0);
	}
	execve(info->path, info->av, info->env);
	write_err("error: cannot execute ");
	write_err(info->path);
	write_err("\n");
	exit(1);
}

void do_it_parent(t_cmd_info *info, t_pipe_info *pipe_info)
{
	if (info->prev_type == kPipe)
	{
		close(pipe_info->prev_read_pipe);
	}
	if (info->curr_type == kPipe)
	{
		close(pipe_info->curr_pipe[1]);
		pipe_info->prev_read_pipe = pipe_info->curr_pipe[0];
	}
}

void ft_cd(t_cmd_info *info)
{
	int i = 0;
	int ret;
	
	while (1)
	{
		if (info->av[i + 1] == NULL)
			break;
		i++;
	}
	if (i != 1)  // TODO 2
	{
		write_err("error: cd: bad arguments\n"); // TODO \n
		return;
	}
	ret = chdir(info->av[1]);
	if (ret == -1)
	{
		write_err("error: cd: cannot change directory to ");
		write_err(info->av[1]);
		write_err("\n");
	}
}

int main(int ac, char **av, char **env)
{
	int i = 1;
	int ret;
	int process_cnt = 0;
	pid_t pid;

	t_cmd_info info = 
	{
		NULL,
		NULL,
		env,
		kNull,
		kNull
	};

	t_pipe_info pipe_info = {{0, 1}, 0};

	if (ac < 2)
		return (0);
	
	while (ac > i)
	{
		if (strncmp(av[i], ";", 2) == 0) {
			i++;
			continue;
		}
		
		i = init_cmd_info(av, &info, i);

		if (strncmp(info.path, "cd", 3) != 0 \
		&& info.curr_type == kPipe)
		{
			ret = pipe(pipe_info.curr_pipe);
			if (ret == -1)
				system_err();
		}
		if (info.prev_type == kSemicolon)
		{
			wait_all_process(process_cnt);
			process_cnt = 0;
		}
		if (strncmp(info.path, "cd", 3) == 0)
		{ //TODO
			ft_cd(&info) ;
			i++;
			continue;
		}

		pid = fork();
		if (pid == -1)
			system_err();
		if (pid == 0)
			do_it_child(&info, &pipe_info);
		do_it_parent(&info, &pipe_info);
		i++;
		process_cnt++;
	}
	wait_all_process(process_cnt);
}