/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:55:41 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/08 17:13:03 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex_fork(t_philo *philo)
{
	if (pthread_mutex_init(&(philo->fork), NULL))
		return (1);
	if (pthread_mutex_init(&(philo->event_lock), NULL))
	{
		pthread_mutex_destroy(&(philo->fork));
		return (1);
	}
	return (0);
}

int	init_mutex(t_philo *philos, t_info *info, t_mutex *mutex)
{
	unsigned int	i;

	if (pthread_mutex_init(&(mutex->mutex_lock), NULL))
		return (1);
	i = 0;
	while (i < info->phc)
	{
		if (init_mutex_fork(&(philos[i])))
		{
			while (i--)
			{
				pthread_mutex_destroy(&(philos[i].fork));
				pthread_mutex_destroy(&(philos[i].event_lock));
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	destory_mutex(t_philo *philos)
{
	unsigned int	i;

	pthread_mutex_destroy(&(philos->mutex->mutex_lock));
	i = 0;
	while (i < philos->info->phc)
	{
		pthread_mutex_destroy(&(philos[i].fork));
		pthread_mutex_destroy(&(philos[i].event_lock));
		i++;
	}
}
