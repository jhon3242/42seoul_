/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:49:53 by choewonjun        #+#    #+#             */
/*   Updated: 2022/08/17 20:34:39 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void redirect(t_info *info)
{
    int fd;

    if (info->count == 2)
    {
        fd = open(info->first_arg, O_RDONLY);
        if (fd < 0)
            error_exit("Open error", EXIT_FAILURE);
        dup2_with_errorck(fd, STDIN_FILENO);
        dup2_with_errorck(info->b[WRITE], STDOUT_FILENO);
    }
}

void    close_unused_fd(t_info *info)
{
    int wr_a;
    int wr_b;

    if (info->pid == 0) // 자식
    {
        wr_a = WRITE;
        wr_b = READ;
    }
    else    // 부모
    {
        wr_a = READ;
        wr_b = WRITE;
    }
    close_with_errorck(info->a[wr_a]);
    close_with_errorck(info->b[wr_b]);
}