/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:12:43 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/08 17:55:57 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_running(t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex->mutex_lock));
	philo->mutex->is_end = 1;
	pthread_mutex_unlock(&(philo->mutex->mutex_lock));
}

static int	join_philos(t_philo *philos, unsigned int i)
{
	while (i--)
		pthread_join(philos[i].thread, NULL);
	return (1);
}

static int	join_all(pthread_t *observe, t_philo *philos, unsigned int i)
{
	join_philos(philos, i);
	pthread_join(*observe, NULL);
	return (1);
}

int	is_end_running(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->mutex->mutex_lock);
	result = philo->mutex->is_end;
	pthread_mutex_unlock(&philo->mutex->mutex_lock);
	return (result);
}

int	running(t_philo *philos, t_info *info)
{
	time_t			cur_time;
	unsigned int	i;
	pthread_t		observe;

	cur_time = get_cur_time();
	philos->info->start_time = cur_time;
	i = 0;
	while (i < info->phc)
	{
		philos[i].last_eating_time = cur_time;
		if (pthread_create(&(philos[i].thread), NULL, do_routine, &philos[i]))
		{
			stop_running(&philos[i]);
			return (join_philos(philos, i));
		}
		i++;
	}
	if (pthread_create(&observe, NULL, observe_philos, philos))
	{
		stop_running(&(philos[i]));
		return (join_all(&observe, philos, i));
	}
	join_all(&observe, philos, i);
	return (0);
}
