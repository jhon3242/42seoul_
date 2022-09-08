/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:05:21 by choewonjun        #+#    #+#             */
/*   Updated: 2022/09/08 17:30:05 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

time_t	get_cur_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

time_t	get_diff_time(time_t start_time)
{
	return (get_cur_time() - start_time);
}

void	print_log(t_philo *philo, enum e_log_type type)
{
	time_t			time_stamp;
	unsigned int	id;

	time_stamp = get_diff_time(philo->info->start_time);
	id = philo->id;
	pthread_mutex_lock(&(philo->mutex->mutex_lock));
	if (!philo->mutex->is_end)
	{
		if (type == FORK)
			printf(C_GREN "%ld %u has taken a fork\n" C_RESET, time_stamp, id);
		else if (type == EAT)
			printf(C_YLLW "%ld %u is eating\n" C_RESET, time_stamp, id);
		else if (type == SLEEP)
			printf(C_BLUE "%ld %u is sleeping\n" C_RESET, time_stamp, id);
		else if (type == THINK)
			printf(C_RED "%ld %u is thinking\n" C_RESET, time_stamp, id);
		else if (type == DEAD)
			printf(C_PRPL "%ld %u died\n" C_RESET, time_stamp, id);
	}
	pthread_mutex_unlock(&(philo->mutex->mutex_lock));
}
