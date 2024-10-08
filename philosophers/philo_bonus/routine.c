/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:43:16 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/11 15:24:02 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_philo *philo)
{
	get_forks(philo);
	sem_wait(philo->shared->event_key[philo->id]);
	philo->last_eating_time = get_cur_time();
	sem_post(philo->shared->event_key[philo->id]);
	print_log(philo, EAT);
	automic_sleep(philo->info->tte);
	if (philo->eat_count++ == philo->info->npe)
		sem_post(philo->shared->full_philos);
	return_fork(philo);
}

static void	sleeping(t_philo *philo)
{
	print_log(philo, SLEEP);
	automic_sleep(philo->info->tts);
}

static void	thinking(t_philo *philo)
{
	print_log(philo, THINK);
	usleep(CONTEXT_SWITCHING_TIME);
}

int	do_routine(t_philo *philo)
{
	pthread_t	dead_observer;

	if (pthread_create(&dead_observer, NULL, observe_dead, philo))
		return (1);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}
