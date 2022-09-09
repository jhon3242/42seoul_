/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:10:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/09 18:34:55 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	return_with_free(pid_t *pids, int return_val)
{
	free(pids);
	return (return_val);
}

static int	wait_end()

int	running(t_philo *philo)
{
	pid_t		*pids;
	unsigned int	i;

	pids = (pid_t *)malloc(sizeof(pid_t) * philo->info->phc);
	if (pids == NULL)
		return (1);
	philo->info->start_time = get_cur_time();
	philo->last_eating_time = philo->info->start_time;
	i = 0;
	while (i < philo->info->phc)
	{
		pids[i] = fork();
		if (pids[i] < 0)
			return (return_with_free(pids, 1));
		else if (pids[i++] == 0)
			exit(do_routine(philo));
	}
	if (observe_full(philo))
		return (return_with_free(pids, 1));
	
	// TODO observe
}