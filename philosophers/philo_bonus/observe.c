/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:06:22 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/11 15:24:41 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	observe_full(t_philo *philo)
{
	pid_t			pid;
	unsigned int	i;

	if (philo->info->npe == 0)
		return (0);
	pid = fork();
	if (pid < 0)
		return (1);
	else if (pid == 0)
	{
		i = philo->info->phc;
		while (--i)
			sem_wait(philo->shared->full_philos);
		exit(0);
	}
	return (0);
}

static void	broadcast_dead(t_philo *philo)
{
	time_t	time_stamp;

	sem_wait(philo->shared->end_key);
	time_stamp = get_diff_time(philo->info->start_time);
	printf(C_PRPL "%ld %u died\n" C_RESET, time_stamp, philo->id);
}

void	*observe_dead(void *_philo)
{
	t_philo	*philo;
	int		is_dead;

	philo = (t_philo *)_philo;
	while (1)
	{
		sem_wait(philo->shared->event_key[philo->id]);
		is_dead = philo->info->ttd <= get_diff_time(philo->last_eating_time);
		sem_post(philo->shared->event_key[philo->id]);
		if (is_dead)
		{
			broadcast_dead(philo);
			exit(0);
		}
		usleep(CONTEXT_SWITCHING_TIME);
	}
}
