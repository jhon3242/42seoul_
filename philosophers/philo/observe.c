/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:18:47 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/08 18:11:12 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	broadcast_dead(t_philo *philo)
{
	print_log(philo, DEAD);
	stop_running(philo);
}

static void	broadcast_all_full(t_philo *philos)
{
	stop_running(philos);
}

static int	check_philos_state(t_philo *philos)
{
	unsigned int	i;
	unsigned int	all_full;
	int				someone_dead;

	someone_dead = 0;
	all_full = (0 < philos->info->npe);
	i = 0;
	while (i < philos->info->phc)
	{
		pthread_mutex_lock(&(philos[i].event_lock));
		all_full &= (philos->info->npe <= philos[i].eat_count);
		if (philos->info->ttd <= get_diff_time(philos[i].last_eating_time))
			someone_dead = 1;
		pthread_mutex_unlock(&(philos[i].event_lock));
		if (someone_dead)
			break ;
		i++;
	}
	if (someone_dead)
		broadcast_dead(&philos[i]);
	else if (all_full)
		broadcast_all_full(philos);
	return (someone_dead || all_full);
}

void	*observe_philos(void *_philos)
{
	t_philo	*philos;

	philos = (t_philo *)_philos;
	while (1)
	{
		if (check_philos_state(philos))
			return (NULL);
		usleep(CONTEXT_SWITCHING_TIME);
	}
}
