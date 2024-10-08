#ifndef MICROSHEOO_H
#define MICROSHEOO_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//err
#include <stdio.h>
#include <fcntl.h>

enum e_cmd_type
{
	kNull,
	kPipe,
	kSemicolon
};

typedef struct s_command_info
{
	char*			path;
	char**			argv;
	char**			envp;
	enum e_cmd_type	prev_type;
	enum e_cmd_type	curr_type;
}	t_command_info;

typedef struct s_pipe_fd
{
	int	curr_pipe[2];
	int	prev_read_pipe;
}	t_pipe;

#endif