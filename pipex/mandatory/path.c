/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:55:04 by choewonjun        #+#    #+#             */
/*   Updated: 2022/08/20 13:37:19 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path_envp(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*get_path_cmd(char **path_env, char *cmd)
{
	char	*tmp;
	char	*ret;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	tmp = ft_strjoin("/", cmd);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (path_env[i])
	{
		ret = ft_strjoin(path_env[i], tmp);
		if (ret == NULL)
			return (NULL);
		if (access(ret, X_OK) == 0)
		{
			free(tmp);
			return (ret);
		}
		free(ret);
		i++;
	}
	free(tmp);
	return (NULL);
}
