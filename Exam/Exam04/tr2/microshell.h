#ifndef MICROSHELL_H
#define MICROSHELL_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum  e_cmd_type
{
	kNull,
	kPipe,
	kSemicolon
};

typedef struct s_cmd_info
{
	char *path;
	char **av;
	char **env;
	enum e_cmd_type prev_type;
	enum e_cmd_type curr_type;
} t_cmd_info;

typedef struct s_pipe_fd
{
	int curr_pipe[2];
	int prev_read_pipe;
} t_pipe;


#endif