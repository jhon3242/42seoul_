#include "myshell.h"

static int	ft_strlen(const char* str)
{
	int len = 0;

	while (*str)
	{
		str++;
		len++;
	}
	return len;
}

static void	ft_put_err(const char* str)
{
	write(2, str, ft_strlen(str));
}

static void	system_err()
{
	ft_put_err("error: fatal\n");
	exit(1);
}

void	safe_dup2_and_close(int old, int new)
{
	int ret;

	ret = dup2(old, new);
	if (ret == -1)
		system_err();
	close(old);
}

int init_cmd_info(char **av, t_cmd_info *info, int i)
{
	info->path = av[i];
	info->av = &av[i];
	info->prev_type = info->curr_type;
	while (1) {
		if (av[i + 1] == NULL \
			|| strncmp(av[i + 1], "|", 2) == 0 \
			|| strncmp(av[i + 1], ";", 2) == 0) 
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

void wati_all_process(int cnt_process)
{
	int ret;

	for (int i = 0; i < cnt_process; i++)
	{
		ret = waitpid(-1, NULL, 0);
		if (ret == -1)
			system_err();
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
	if (i != 1)
	{
		ft_put_err("error : cd: bad arguments\n");
		return ;
	}
	ret = chdir(info->av[1]);
	if (ret == -1)
	{
		ft_put_err("error: cd: cannot change directory to ");
		ft_put_err(info->av[1]);
		ft_put_err("\n");
	}
}


void do_it_child(t_cmd_info* info, t_pipe* pipe_info)
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
	ft_put_err("error: cannot execute ");
	ft_put_err(info->path);
	ft_put_err("\n");
	exit(1);
}

void do_it_parent(t_cmd_info* info, t_pipe *pip_info)
{
	if (info->prev_type == kPipe)
		close(pip_info->prev_read_pipe);
	if (info->curr_type == kPipe)
	{
		close(pip_info->curr_pipe[1]);
		pip_info->prev_read_pipe = pip_info->curr_pipe[0];
	}
}

int main(int ac, char **av, char **env)
{
	
	int i = 1;
	int ret;
	int cnt_process = 0;
	pid_t pid;


	t_cmd_info info = 
	{
		NULL,
		NULL,
		env,
		kNull,
		kNull
	};
	t_pipe pipe_info = {{0, 1}, 0};

	if (ac < 2)
		return 0;
	while (ac > i)
	{
		if (strncmp(av[i], ";", 2) == 0)
		{
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
			wati_all_process(cnt_process);
			cnt_process = 0;
		}
		if (strncmp(info.path, "cd", 3) == 0)
		{
			ft_cd(&info);
			i++;
			continue;
		}
		pid = fork();
		if (pid == -1)
			system_err();
		if (pid == 0)
			do_it_child(&info, &pipe_info);
		do_it_parent(&info, &pipe_info);

		cnt_process++;
		i++;
	}
	wati_all_process(cnt_process);
}