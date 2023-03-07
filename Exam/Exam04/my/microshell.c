#include "microshell.h"

int	write_err(char *str, char *av)
{
	while (str && *str)
		write(2, str++, 1);
	if (av)
		while (*av)
			write(2, av++, 1);
	write(2, "\n", 1);
	return (1);
}

int ft_exe(char **av, int i , int t_fd, char **env)
{
	av[i] = NULL;
	dup2(t_fd, STDIN_FILENO);
	close(t_fd);
	execve(av[0], av, env);
	return (write_err("error: cannot execute executable_that_failed", av[0]));
}

int main(int ac, char **av, char**env)
{
	int t_fd;
	int i;
	int fd[2];

	t_fd = dup(STDIN_FILENO);
	i = 0;
	while(av[i] && av[i + 1] )
	{
		av = &av[i + 1];
		i = 0;
		while(av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				write_err("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				write_err("error: cd: cannot change directory to path_to_change", av[1]);
		}
		else if (i != 0 && (av[i] == NULL || strcmp(av[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (ft_exe(av, i, t_fd, env))
					return (1);
			}
			else
			{
				close(t_fd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				t_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(av[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_exe(av, i, t_fd, env))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(t_fd);
				t_fd = fd[0];
			}
		}
	}
	close(t_fd);
	return (0);
}