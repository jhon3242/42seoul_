/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:10:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/11 15:24:37 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	return_with_free(pid_t *pids, int return_val)
{
	free(pids);
	return (return_val);
}

static void	wait_end(t_philo *philo, pid_t *pids)
{
	unsigned int	i;
	int				status;

	waitpid(-1, &status, 0);
	i = 0;
	while (i < philo->info->phc)
	{
		kill(pids[i], SIGTERM);
		i++;
	}
	i = philo->info->phc;
	while (i--)
		sem_post(philo->shared->full_philos);
}

int	running(t_philo *philo)
{
	pid_t			*pids;
	unsigned int	i;

	pids = (pid_t *)malloc(sizeof(pid_t) * philo->info->phc);
	if (pids == NULL)
		return (1);
	philo->info->start_time = get_cur_time();
	philo->last_eating_time = philo->info->start_time;
	i = 0;
	while (i < philo->info->phc)
	{
		philo->id = i + 1;
		pids[i] = fork();
		if (pids[i] == -1)
			return (return_with_free(pids, 1));
		else if (pids[i++] == 0)
			exit(do_routine(philo));
	}
	if (observe_full(philo))
	{
		return (return_with_free(pids, 1));
	}
	wait_end(philo, pids);
	return (return_with_free(pids, 0));
}
