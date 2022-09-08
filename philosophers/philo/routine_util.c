/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:13:42 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/08 15:02:44 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_log(philo, FORK);
	pthread_mutex_lock(philo->rfork);
	print_log(philo, FORK);
}

void	return_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	automic_sleep(time_t time_to_wait)
{
	time_t	start_time;

	start_time = get_cur_time();
	while (get_diff_time(start_time) < time_to_wait)
		usleep(CONTEXT_SWITCHING_TIME);
}
