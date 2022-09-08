/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:59:18 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/08 18:11:06 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*one_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_log(philo, FORK);
	while (!is_end_running(philo))
		usleep(CONTEXT_SWITCHING_TIME);
	pthread_mutex_unlock(philo->lfork);
	return (NULL);
}

static int	eating(t_philo *philo)
{
	get_forks(philo);
	pthread_mutex_lock(&(philo->event_lock));
	philo->last_eating_time = get_cur_time();
	pthread_mutex_unlock(&(philo->event_lock));
	print_log(philo, EAT);
	automic_sleep(philo->info->tte);
	pthread_mutex_lock(&(philo->event_lock));
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->event_lock));
	return_fork(philo);
	return (is_end_running(philo));
}

static int	sleeping(t_philo *philo)
{
	print_log(philo, SLEEP);
	automic_sleep(philo->info->tts);
	return (is_end_running(philo));
}

static int	thinking(t_philo *philo)
{
	print_log(philo, THINK);
	usleep(CONTEXT_SWITCHING_TIME);
	return (is_end_running(philo));
}

void	*do_routine(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	if (philo->info->phc == 1)
		return (one_philo_routine(philo));
	if (philo->id % 2 == 0)
		usleep(CONTEXT_SWITCHING_TIME);
	while (1)
	{
		if (eating(philo))
			return (NULL);
		if (sleeping(philo))
			return (NULL);
		if (thinking(philo))
			return (NULL);
	}
	return (NULL);
}
