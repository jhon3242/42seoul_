/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:11:12 by choewonjun        #+#    #+#             */
/*   Updated: 2022/09/07 16:15:24 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_t_philo(t_philo **philos, t_info *info)
{
	*philos = malloc(sizeof(t_philo) * info->phc);
	if (*philos == NULL)
		return (1);
	return (0);
}

void	init_philos(t_philo *philos, t_info *info, t_mutex *mutex)
{
	unsigned int	i;

	mutex->is_end = 0;
	i = 0;
	while (i < info->phc)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].lfork = &(philos[i].fork);
		philos[i].rfork = &(philos[(i + 1) % info->phc].fork);
		philos[i].info = info;
		philos[i].mutex = mutex;
		i++;
	}
}

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