/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:55:04 by choewonjun        #+#    #+#             */
/*   Updated: 2022/08/17 21:33:10 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *get_path_envp(char *envp[])
{
    int     i;

    i = 0;
    while (envp[i] != NULL)
    {
        if (ft_strncmp("PATH=", envp[i], 5) == 0)
            return (ft_strdup(envp[i] + 5));
        i++;
    }
    return (NULL);
}

char    *get_path_cmd(char **path_env, char *cmd)
{
    
}