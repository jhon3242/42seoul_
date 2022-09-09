/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:45:21 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/09 17:53:33 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_forks(t_philo *philo)
{
	if (philo->info->phc != 1)
		sem_wait(philo->shared->forks_key);
	sem_wait(philo->shared->forks);
	print_log(philo, FORK);
	sem_wait(philo->shared->forks);
	print_log(philo, FORK);
}

void	return_fork(t_philo *philo)
{
	sem_post(philo->shared->forks);
	sem_post(philo->shared->forks);
	sem_post(philo->shared->forks_key);
}

void	automic_sleep(time_t time_to_wait)
{
	time_t	start_time;

	start_time = get_cur_time();
	while (get_diff_time(start_time) < time_to_wait)
		usleep(CONTEXT_SWITCHING_TIME);
}